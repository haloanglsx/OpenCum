git #ifndef TECHNOLOGYMANAGER_H
#define TECHNOLOGYMANAGER_H

#include "Technology.h"
#include <vector>
#include <string>

class TechnologyManager {
private:
    std::vector<Technology*> technologies;

public:
    ~TechnologyManager();
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void addTechnology(const std::string& name, const std::string& type);
    void displayAll() const;
    void editTechnology(int index);
    void deleteTechnology(int index);
};

#endif // TECHNOLOGYMANAGER_H
