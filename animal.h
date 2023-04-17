#include <vector>
#include "cell.h"

class Animal : public Cell
{
private:
    std::vector<Genome> v;
public:
    Animal();
    Animal(std::vector<Genome> g) : Cell(g){};
    int sim_pct(Animal);
    bool operator==(Animal &);
    Animal as_reprod();
    Animal operator+(Animal &);
    void cell_death();
};