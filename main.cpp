#include <iostream>
#include "animal.h"

using namespace std;

int main()
{
    Genome g;
    Cell c;
    Animal a;
    while(true)
    {
        int n;
        cout << "choose a number between 0 and 19: " << endl
            << "1 to make a Genome" << endl
            << "2 to set RNA" << endl
            << "3 to set DNA" << endl
            << "4 to make DNA from RNA" << endl
            << "5 to small jump in Genome" << endl
            << "6 to big jump in Genome" << endl
            << "7 to reverse jump in Genome" << endl
            << "8 to make a Cell" << endl
            << "9 to check cell-death in Cell" << endl
            << "10 to big jump in Cell" << endl
            << "11 to small jump in Cell" << endl
            << "12 to reverse jump in Cell" << endl
            << "13 to find complementary palindromes in Cell" << endl
            << "14 to make an Animal" << endl
            << "15 to calculate similarity percentage" << endl
            << "16 to identify if same species" << endl
            << "17 to asexual reproduction" << endl
            << "18 to sexual reproduction" << endl
            << "19 to check cell-death in Animal" << endl
            << "0 to exit" << endl;
        cin >> n;
        if(n == 1)
        {
            string r;
            string d;
            cout << "Enter a string of 'A' & 'T' & 'C' & 'G' to make RNA: ";
            cin >> r;
            cout << "Enter a string of 'A' & 'T' & 'C' & 'G' to make DNA: ";
            cin >> d;
            if(g.set_RNA(r) && g.set_DNA(d))
            {
                cout << "Genome set" << endl
                    << "RNA: " << g.get_rna().get_rna() << endl
                    << "DNA: " << g.get_dna().get_a() << endl
                    << "     " << g.get_dna().get_b() << endl;
            }
        }
        else if(n == 2)
        {
            string r;
            cout << "Enter a string to set RNA: " << endl;
            cin >> r;
            if(g.set_RNA(r))
            {
                cout << "RNA set" << endl
                    << "RNA: " << g.get_rna().get_rna() << endl;
            }
        }
        else if(n == 3)
        {
            string d;
            cout << "Enter a string to set DNA: " << endl;
            cin >> d;
            if(g.set_DNA(d))
            {
                cout << "DNA set" << endl
                    << "DNA: " << g.get_dna().get_a() << endl
                    << "     " << g.get_dna().get_b() << endl;
            }
        }
        else if(n == 4)
        {
            g.DNA_from_RNA(g.get_rna());
        }
        else if(n == 5)
        {
            char a, b;
            int n;
            cout << "Enter the character you want to replace: " << endl;
            cin >> a;
            cout << "How many of " << a << "s you want to replace? " << endl;
            cin >> n;
            cout << "Enter the target character: " << endl;
            cin >> b;
            g.small_jump(a, b, n);
            cout << "RNA: " << g.get_rna().get_rna() << endl
                << "DNA: " << g.get_dna().get_a() << endl
                << "     " << g.get_dna().get_b() << endl;
        }
        else if(n == 6)
        {
            string s1, s2;
            cout << "Enter the string you want to replace: " << endl;
            cin >> s1;
            cout << "Enter the target string: " << endl;
            cin >> s2;
            g.big_jump(s1, s2);
            cout << "RNA: " << g.get_rna().get_rna() << endl
                << "DNA: " << g.get_dna().get_a() << endl
                << "     " << g.get_dna().get_b() << endl;
        }
        else if(n == 7)
        {
            string s;
            cout << "Enter the string: " << endl;
            cin >> s;
            g.reverse_jump(s);
            cout << "RNA: " << g.get_rna().get_rna() << endl
                << "DNA: " << g.get_dna().get_a() << endl
                << "     " << g.get_dna().get_b() << endl;
        }
        else if(n == 8)
        {
            int n;
            cout << "Enter number of chromosomes: " << endl;
            cin >> n;
            vector<Genome> v(n);
            for(int i = 0; i < n; i++)
            {
                string s1, s2;
                cout << "Enter 2 strings to set chromosomes: " << endl;
                cin >> s1 >> s2;
                Genome gv(s1, s2);
                v[i] = gv;
            }
            c = Cell(v);
            cout << "Cell set" << endl
                << "Cell chromosomes are: " << endl;
            for(int i = 0; i < n; i++)
            {
                cout << v[i].get_dna().get_a() << endl
                    << v[i].get_dna().get_b() << endl
                    << endl;
            }
        }
        else if(n == 9)
        {
            c.cell_death();
        }
        else if(n == 10)
        {
            int n, m;
            string s1, s2;
            cout << "Enter number of first chromosome: " << endl;
            cin >> n;
            cout << "Enter first string: " << endl;
            cin >> s1;
            cout << "Enter number of second chromosome: " << endl;
            cin >> m;
            cout << "Enter second string: " << endl;
            cin >> s2;
            c.big_jump(s1, n, s2, m);
            cout << "Cell: " << endl;
            for(int i = 0; i < n; i++)
            {
                cout << c.get_v()[i].get_dna().get_a() << endl
                    << c.get_v()[i].get_dna().get_b() << endl
                    << endl;
            }
        }
        else if(n == 11)
        {
            char a, b;
            int n, m;
            cout << "Chromosome number: " << endl;
            cin >> m;
            cout << "Enter the character you want to replace: " << endl;
            cin >> a;
            cout << "How many of " << a << "s you want to replace? " << endl;
            cin >> n;
            cout << "Enter the target character: " << endl;
            cin >> b;
            c.small_jump(a, b, n, m);
            cout << "Cell: " << endl;
            for(int i = 0; i < n; i++)
            {
                cout << c.get_v()[i].get_dna().get_a() << endl
                    << c.get_v()[i].get_dna().get_b() << endl
                    << endl;
            }
        }
        else if(n == 12)
        {
            string s;
            int n;
            cout << "Chromosome number: " << endl;
            cin >> n;
            cout << "Enter the string: " << endl;
            cin >> s;
            c.reverse_jump(s, n);
            cout << "Cell: " << endl;
            for(int i = 0; i < n; i++)
            {
                cout << c.get_v()[i].get_dna().get_a() << endl
                    << c.get_v()[i].get_dna().get_b() << endl
                    << endl;
            }
        }
        else if(n == 13)
        {
            int n;
            cout << "Chromosome number: " << endl;
            cin >> n;
            c.palindrome(n);
        }
        else if(n == 14)
        {
            int n;
            cout << "Enter number of chromosomes: " << endl;
            cin >> n;
            vector<Genome> v(n);
            for(int i = 0; i < n; i++)
            {
                string s1, s2;
                cout << "Enter 2 strings to set chromosomes: " << endl;
                cin >> s1 >> s2;
                Genome gv(s1, s2);
                v[i] = gv;
            }
            a = Animal(v);
            cout << "Animal set" << endl
                << "Animal Cell: " << endl;
            for(int i = 0; i < n; i++)
            {
                cout << v[i].get_dna().get_a() << endl
                    << v[i].get_dna().get_b() << endl
                    << endl;
            }
        }
        else if(n == 15)
        {
            Animal a1;
            int n;
            cout << "Enter number of chromosomes of the animal to compare: " << endl;
            cin >> n;
            vector<Genome> v(n);
            for(int i = 0; i < n; i++)
            {
                string s1, s2;
                cout << "Enter 2 strings to set chromosomes: " << endl;
                cin >> s1 >> s2;
                Genome gv(s1, s2);
                v[i] = gv;
            }
            a1 = Animal(v);
            int sp = a.sim_pct(a1);
            cout << "Similarity percentage is " << sp << endl;
        }
        else if(n == 16)
        {
            Animal a1;
            int n;
            cout << "Enter number of chromosomes of the animal to compare: " << endl;
            cin >> n;
            vector<Genome> v(n);
            for(int i = 0; i < n; i++)
            {
                string s1, s2;
                cout << "Enter 2 strings to set chromosomes: " << endl;
                cin >> s1 >> s2;
                Genome gv(s1, s2);
                v[i] = gv;
            }
            a1 = Animal(v);
            if(a == a1)
                cout << "Animals are of the same species" << endl;
            else
                cout << "Animals are not of the same species" << endl;
        }
        else if(n == 17)
        {
            Animal a1 = a.as_reprod();
            cout << "Borned Animal cell: " << endl;
            for(int i = 0; i < a.get_v().size(); i++)
            {
                cout << a1.get_v()[i].get_dna().get_a() << endl;
                cout << a1.get_v()[i].get_dna().get_b() << endl;
            }
        }
        else if(n == 18)
        {
            Animal a1;
            int n;
            cout << "Enter number of chromosomes of the pair animal: " << endl;
            cin >> n;
            vector<Genome> v(n);
            for(int i = 0; i < n; i++)
            {
                string s1, s2;
                cout << "Enter 2 strings to set chromosomes: " << endl;
                cin >> s1 >> s2;
                Genome gv(s1, s2);
                v[i] = gv;
            }
            a1 = Animal(v);
            Animal a2;
            a2 = a + a1;
            cout << "Borned Animal cell: " << endl;
            for(int i = 0; i < a.get_v().size(); i++)
            {
                cout << a2.get_v()[i].get_dna().get_a() << endl;
                cout << a2.get_v()[i].get_dna().get_b() << endl;
            }
        }
        else if(n == 19)
        {
            a.cell_death();
        }
        else if(n == 0)
            break;
    }
}