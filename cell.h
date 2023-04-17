#include <string>
#include <vector>
class DNA
{
private:
    std::string a;
    std::string b;
public:
    bool set_dna(std::string);
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
    bool set_rna(std::string);
    std::string get_rna();
};
class Genome
{
private:
    RNA rna;
    DNA dna;
public:
    Genome();
    Genome(std::string, std::string);
    bool set_RNA(std::string);
    bool set_DNA(std::string);
    RNA get_rna();
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
    Cell();
    Cell(std::vector<Genome> vg);
    std::vector<Genome> get_v();
    void read_v();
    void cell_death();
    void big_jump(std::string, int, std::string, int);
    void small_jump(char, char, int, int);
    void reverse_jump(std::string, int);
    void palindrome(int);
};