#include <string>
#include <vector>
class DNA
{
private:
    std::string a;
    std::string b;
public:
    void set_dna(std::string);
    void set_a(std::string);
    void set_b(std::string);
    std::string get_a();
    std::string get_b();
};
class RNA
{
private:
    std::string rna;
public:
    void set_rna(std::string);
    std::string get_rna();
};
class Genome
{
private:
    RNA rna;
    DNA dna;
public:
    Genome(std::string, std::string);
    void set_RNA(std::string);
    void set_DNA(std::string);
    DNA get_dna();
    void DNA_from_RNA(RNA);
    void small_jump(char, char, int);
    void big_jump(std::string, std::string);
    void reverse_jump(std::string);
};
class Cell : public Genome
{
private:
    std::vector<Genome> v;
public:
    void read_v();
    void death_cell();
    void big_jump(std::string, int, std::string, int);
    void small_jump(char, char, int, int);
    void reverse_jump(std::string, int);
    void palindrome(int);
};