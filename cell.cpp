#include <iostream>
#include <bits/stdc++.h>
#include "cell.h"
using namespace std;

void DNA::set_a(string a1) { a = a1; }
void DNA::set_b(string b1) { b = b1; }
string DNA::get_a() { return a; }
string DNA::get_b() { return b; }
bool DNA::set_dna(string d)
{
    int i = 0;
    while(i < d.size())
    {
        if(d[i] != 'A' && d[i] != 'T' && d[i] != 'C' && d[i] != 'G')
        {
            cout << "invalid input" << endl;
            return 0;
        }
        i++;
    }
    a = d;
    string d2;
    for(int j = 0; j < d.size(); j++)
    {
        if(d[j] == 'A')
            d2 += 'T';
        else if(d[j] == 'T')
            d2 += 'A';
        else if(d[j] == 'C')
            d2 += 'G';
        else
            d2 += 'C';
    }
    b = d2;
    return 1;
}

string RNA::get_rna() { return rna; }
bool RNA::set_rna(string r)
{ 
    int i = 0;
    while(i < r.size())
    {
        if(r[i] != 'A' && r[i] != 'T' && r[i] != 'C' && r[i] != 'G')
        {
            cout << "invalid input" << endl;
            return 0;
        }
        i++;
    }
    rna = r;
    return 1;
}

Genome::Genome() {};
bool Genome::set_RNA(string r)
{
    if(rna.set_rna(r))
        return 1;
    else
        return 0;
}
bool Genome::set_DNA(string d) 
{
    if(dna.set_dna(d))
        return 1;
    else
        return 0;
}
Genome::Genome(string a, string b)
{
    RNA *rna = NULL;
    dna.set_a(a);
    dna.set_b(b);
}
RNA Genome::get_rna()
{
    return rna;
}
DNA Genome::get_dna()
{
    return dna;
}
void Genome::DNA_from_RNA(RNA r)
{
    DNA dfr;
    if(dfr.set_dna(r.get_rna()))
    {
        cout << "DNA set from RNA: " << dfr.get_a() << endl
            << "                  " << dfr.get_b() << endl;
    }
}
void Genome::small_jump(char a, char b, int n)
{
    string R = rna.get_rna();
    for(int i = 0, m = 0; i < R.size() && m < n; i++)
    {
        if(R[i] == a)
        {
            R[i] = b;
            m++;
        }
    }
    rna.set_rna(R);
    string d1 = dna.get_a();
    string d2 = dna.get_b();
    for(int i = 0, m = 0; i < d1.size() && m < n; i++)
    {
        if(d1[i] == a)
        {
            d1[i] = b;
            m++;
        }
        if(d2[i] == a)
        {
            d2[i] = b;
            if(b == 'A')
                d1[i] = 'T';
            else if(b == 'T')
                d1[i] = 'A';
            else if(b == 'C')
                d1[i] = 'G';
            else if(b == 'G')
                d1[i] = 'C';
            m++;
        }
    }
    dna.set_dna(d1);
}
void Genome::big_jump(string s1, string s2)
{
    if(s1.size() < 0 || s2.size() < 0)
        cout << "invalid input";
    else
    {
        string rs = rna.get_rna();
        for(int i = 0; i < rs.size() - s1.size(); i++)
        {
            if(rs.substr(i, s1.size()) == s1)
            {
                rs = rs.substr(0, i) + s2 + rs.substr(i+s2.size(), rs.size() - (s2.size() + i + 1));
                break;
            }
        }
        rna.set_rna(rs);
        string d1 = dna.get_a();
        string d2 = dna.get_b();
        bool sup = 0;
        for(int i = 0; i < d1.size() - s1.size(); i++)
        {
            if(d1.substr(i, s1.size()) == s1)
            {
                d1 = d1.substr(0, i) + s2 + d1.substr(i+s2.size(), d1.size() - (s2.size() + i + 1));
                break;
            }
            if(d2.substr(i, s1.size()) == s1)
            {
                d2 = d2.substr(0, i) + s2 + d2.substr(i+s2.size(), d2.size() - (s2.size() + i + 1));
                sup = 1;
                break;
            }
        }
        if(sup == 1)
        {
            dna.set_dna(d2);
            dna.set_dna(dna.get_b());
        }
        else
            dna.set_dna(d1);
    }
}
void Genome::reverse_jump(string s)
{
    if(s.size() < 0)
        cout << "invalid input";
    else
    {
        string rev;
        for(int i = s.size()-1; i >= 0; i--)
        {
            rev += s[i];
        }
        string r = rna.get_rna();
        for(int i = 0; i < r.size() - s.size(); i++)
        {
            if(r.substr(i, s.size()) == s)
            {
                r = r.substr(0, i) + rev + r.substr(i+s.size(), r.size() - (s.size() + i));
                break;
            }
        }
        rna.set_rna(r);

        string d1 = dna.get_a();
        string d2 = dna.get_b();
        bool sup = 0;
        for(int i = 0; i < d1.size() - s.size(); i++)
        {
            if(d1.substr(i, s.size()) == s)
            {
                d1 = d1.substr(0, i) + rev + d1.substr(i+s.size(), d1.size() - (s.size() + i));
                break;
            }
            else if(d2.substr(i, s.size()) == s)
            {
                d2 = d2.substr(0, i) + rev + d2.substr(i+s.size(), d2.size() - (s.size() + i));
                sup = 1;
                break;
            }
        }
        if(sup == 1)
        {
            dna.set_dna(d2);
            dna.set_dna(dna.get_b());
        }
        else
            dna.set_dna(d1);
    }
}

Cell::Cell() {}
Cell::Cell(std::vector<Genome> vg) { v = vg; }
vector<Genome> Cell::get_v()
{
    return v;
}
void Cell::read_v()
{
    int size;
    cin >> size;
    vector<string> v1;
    vector<string> v2;
    for(int i = 0; i < size; i++)
    {
        string a, b;
        cin >> a >> b;
        v1[i] = a;
        v2[i] = b;
    }
    for(int i = 0; i < size; i++)
        v[i] = Genome(v1[i], v2[i]);
}
bool Cell::cell_death()
{
    for(int i = 0; i < v.size(); i++)
    {
        string a = v[i].get_dna().get_a();
        string b = v[i].get_dna().get_b();
        int count = 0; 
        int AT = 0;
        int CG = 0;
        for(int j = 0; j < a.size(); j++)
        {
            if(a[j] == 'A' && b[j] != 'T')
                count++;
            else if(a[j] == 'T' && b[j] != 'A')
                count++;
            else if(a[j] == 'C' && b[j] != 'G')
                count++;
            else if(a[j] == 'G' && b[j] != 'C')
                count++;
            if(a[j] == 'A' && b[j] == 'T')
                AT++;
            else if(a[j] == 'T' && b[j] == 'A')
                AT++;
            else if(a[j] == 'C' && b[j] == 'G')
                CG++;
            else if(a[j] == 'G' && b[j] == 'C')
                CG++;
        }
        if(count < 5 && AT <= 3*CG)
        {
            cout << "No cell-death detected." << endl;
            return 0;
        }
        else
        {
            cout << "Cell deleted." << endl;
            return 1;
        }
    }
}
void Cell::big_jump(string s1, int n, string s2, int m)
{
    if(s1.size() < 0 || s2.size() < 0)
        cout << "invalid input";
    else
    {
        string d11 = v[n-1].get_dna().get_a();
        string d12 = v[n-1].get_dna().get_b();
        bool sup1 = 0;
        for(int i = 0; i < d11.size() - s1.size(); i++)
        {
            if(d11.substr(i, s1.size()) == s1)
            {
                d11 = d11.substr(0, i) + s2 + d11.substr(i+s2.size(), d11.size() - (s2.size() + i));
                break;
            }
            if(d12.substr(i, s1.size()) == s1)
            {
                d12 = d12.substr(0, i) + s2 + d12.substr(i+s2.size(), d12.size() - (s2.size() + i));
                sup1 = 1;
                break;
            }
        }
        if(sup1 == 1)
        {
            v[n-1].get_dna().set_dna(d12);
            v[n-1].get_dna().set_dna(v[n-1].get_dna().get_b());
        }
        else
            v[n-1].get_dna().set_dna(d11);
        string d21 = v[m-1].get_dna().get_a();
        string d22 = v[m-1].get_dna().get_b();
        bool sup2 = 0;
        for(int i = 0; i < d21.size() - s2.size(); i++)
        {
            if(d21.substr(i, s2.size()) == s2)
            {
                d21 = d21.substr(0, i) + s1 + d21.substr(i+s1.size(), d21.size() - (s1.size() + i));
                break;
            }
            if(d22.substr(i, s2.size()) == s2)
            {
                d22 = d22.substr(0, i) + s1 + d22.substr(i+s1.size(), d22.size() - (s1.size() + i));
                sup2 = 1;
                break;
            }
        }
        if(sup2 == 1)
        {
            v[m-1].get_dna().set_dna(d22);
            v[m-1].get_dna().set_dna(v[m-1].get_dna().get_b());
        }
        else
            v[m-1].get_dna().set_dna(d21);
    }
}
void Cell::small_jump(char a, char b, int n, int m)
{
    string d1 = v[m].get_dna().get_a();
    string d2 = v[m].get_dna().get_b();
    for(int i = 0, t = 0; i < d1.size() && t <= n; i++)
    {
        if(d1[i] = a)
        {
            d1[i] = b;
            t++;
        }
        else if(d2[i] = a)
        {
            d2[i] = b;
            if(b == 'A')
                d1[i] = 'T';
            else if(b == 'T')
                d1[i] = 'A';
            else if(b == 'C')
                d1[i] = 'G';
            else if(b == 'G')
                d1[i] = 'C';
            t++;
        }
    }
    v[m].get_dna().set_dna(d1);
}
void Cell::reverse_jump(string s, int n)
{
    if(s.size() < 0)
        cout << "invalid input";
    else
    {
        string rev;
        for(int i = s.size()-1; i >= 0; i--)
            rev += s[i];
        string d1 = v[n].get_dna().get_a();
        string d2 = v[n].get_dna().get_b();
        bool sup = 0;
        for(int i = 0; i < d1.size() - s.size(); i++)
        {
            if(d1.substr(i, s.size()) == s)
            {
                d1 = d1.substr(0, i) + rev + d1.substr(i+s.size(), d1.size() - (s.size() + i));
                break;
            }
            else if(d2.substr(i, s.size()) == s)
            {
                d2 = d2.substr(0, i) + rev + d2.substr(i+s.size(), d2.size() - (s.size() + i));
                sup = 1;
                break;
            }
        }
        if(sup == 1)
        {
            v[n].get_dna().set_dna(d2);
            v[n].get_dna().set_dna(v[n].get_dna().get_b());
        }
        else
            v[n].get_dna().set_dna(d1);
    }
}
void Cell::palindrome(int n)
{
    string s = v[n].get_dna().get_a();
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = s.size() - 1; j > i; j--)
        {
            bool c;
            for(int x = i; x < (j-i)/2; x++)
            {
                c = 0;
                if(s[i-x] == 'A' && s[j-x] == 'T')
                    c = 1;
                else if(s[i-x] == 'T' && s[j-x] == 'A')
                    c == 1;
                else if(s[i-x] == 'C' && s[j-x] == 'G')
                    c == 1;
                else if(s[i-x] == 'G' && s[j-x] == 'C')
                    c == 1;
                else 
                    break;
            }
            if(c == 1)
            {
                cout  << s.substr(i, (j-i)/2 +1) << endl;
                i += ((j-i+1)/2) - 1;
            }
        }
    }
}