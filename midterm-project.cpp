#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DNA
{
private:
    string a;
    string b;
public:
    void set_dna(string);
    string get_a() { return a; }
    string get_b() { return b; }
};
void DNA::set_dna(string d)
{
    int i = 0;
    bool check = 1;
    while(i < d.size())
    {
        if(d[i] != 'A' && d[i] != 'T' && d[i] != 'C' && d[i] != 'G')
        {
            cout << "invalid input";
            check = 0;
            break;
        }
        else
            i++;
    }
    if(i == d.size() && check == 1)
    {
        a = d;
        string d2;
        for(int j = 0; j < d.size(); j++)
        {
            if(d[j] == 'A')
                d2[j] = 'T';
            else if(d[j] == 'T')
                d2[j] = 'A';
            else if(d[j] == 'C')
                d2[j] = 'G';
            else
                d2[j] = 'C';
        }
        b = d2;
    }
}

class RNA
{
private:
    string rna;
public:
    void set_rna(string);
    string get_rna() { return rna; }
};
void RNA::set_rna(string r)
{ 
    int i = 0;
    bool check = 1;
    while(i < r.size())
    {
        if(r[i] != 'A' && r[i] != 'T' && r[i] != 'C' && r[i] != 'G')
        {
            cout << "invalid input";
            check = 0;
            break;
        }
        else
            i++;
    }
    if(i == r.size() && check == 1)
        rna = r;
}

class Genome
{
private:
    RNA rna;
    DNA dna;
public:
    Genome(string rna, string dna) { 
        set_RNA(rna);
        set_DNA(dna);
    }
    void set_RNA(string r) { rna.set_rna(r); }
    void set_DNA(string d) { dna.set_dna(d); }
    void DNA_from_RNA(RNA);
    void small_jump(char, char, int);
    void big_jump(string, string);
    void reverse_jump(string);
};

void Genome::DNA_from_RNA(RNA r)
{
    DNA dfr;
    dfr.set_dna(r.get_rna());
    cout << dfr.get_a() << endl;
    cout << dfr.get_b() << endl;
}

void Genome::small_jump(char a, char b, int n)
{
    string R = rna.get_rna();
    for(int i = 0, m = 0; i < R.size(), m <= n; i++)
    {
        if(R[i] = a)
        {
            R[i] = b;
            m++;
        }
    }
    rna.set_rna(R);
    string d1 = dna.get_a();
    string d2 = dna.get_b();
    for(int i = 0, m = 0; i < D.size() && m <= n; i++)
    {
        if(d1[i] = a)
        {
            d1[i] = b;
            m++;
        }
        if(d2[i] = a)
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
        cout < "invalid input";
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
        cout < "invalid input";
    else
    {
        string rev = reverse(s.begin(), s.end());
        string r = rna.get_rna();
        for(int i = 0; i < r.size() - s.size(); i++)
        {
            if(r.substr(i, s.size()) == s)
            {
                r = r.substr(0, i) + rev + r.substr(i+s.size(), r.size() - (s.size() + i + 1));
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
                d1 = d1.substr(0, i) + rev + d1.substr(i+s.size(), d1.size() - (s.size() + i + 1));
                break;
            }
            if(d2.substr(i, s.size()) == s)
            {
                d2 = d2.substr(0, i) + rev + d2.substr(i+s.size(), d2.size() - (s.size() + i + 1));
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
int main() {}