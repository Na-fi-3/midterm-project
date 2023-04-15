#include <iostream>
#include <bits/stdc++.h>
#include "cell.h"
#include "animal.h"

using namespace std;

Animal::Animal() {};
int Animal::sim_pct(Animal a)
{
    int t = 0;
    vector<Genome> v2 = a.get_v();
    for(int i = 0, j = 0; i < v.size() && j < v2.size(); i++, j++)
    {
        if(v[i].get_dna().get_a() == v2[j].get_dna().get_a())
            t++;
    }
    int sp = (t * 100) / min(v.size(), v2.size());
    return sp;
}
bool Animal::operator==(Animal & a)
{
    vector<Genome> v2 = a.get_v();
    if(v.size() == v2.size() && (this->sim_pct(a)) > 70)
        return true;
    else
        return false;
}
Animal Animal::as_reprod()
{
    vector<Genome> v1;
    for(int i = 0; i < v.size(); i++)
    {
        v1.push_back(v[i]);
        v1.push_back(v[i]);
    }
    while(true)
    {
        random_shuffle(v1.begin(), v1.end());

        vector<Genome> vg(v.size());
        copy(v1.begin(), v1.begin() + v.size(), vg.begin());
        
        Animal a(vg);
        if (this->sim_pct(a) >= 70)
            return a;
    }
}
Animal Animal::operator+(Animal & a)
{
    vector<Genome> v1 = (this->as_reprod()).get_v();
    vector<Genome> v2 = (a.as_reprod()).get_v();
    int c = v1.size()/2 + v2.size()/2;
    if(c % 2 != 0)
        cout << "reproduction can't be done." << endl;
    else
    {
        vector<Genome> v3(v1.size()/2);
        vector<Genome> v4(v2.size()/2);
        while(true)
        {
            random_shuffle(v1.begin(), v1.end());
            copy(v1.begin(), v1.begin() + v1.size()/2, v3.begin());
            Animal a1(v3);
            if (this->sim_pct(a1) >= 70)
                break;
        }
        while(true)
        {
            random_shuffle(v2.begin(), v2.end());
            copy(v2.begin(), v2.begin() + v2.size()/2, v4.begin());
            Animal a2(v4);
            if (a.sim_pct(a2) >= 70)
                break;
        }
        vector<Genome> v5;
        for(int i = 0; i < c/2; i++)
        {
            v5.push_back(v3[i]);
        }
        for(int i = 0; i < c/2; i++)
        {
            v5.push_back(v4[i]);
        }
        return Animal(v5);
    } 
}
bool Animal::cell_death()
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
        if(count >= 5 || AT > 3*CG)
        {
            swap(v[i], v[v.size()-1]);
            v.pop_back();
            return 1;
        }
        else
            return 0;
    }
}