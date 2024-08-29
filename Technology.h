#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H
#include <string>
#include <iostream>

class Technology {
public:
    Technology(const std::string& name, const std::string& type);
    virtual ~Technology() {}

    std::string getName() const;

    virtual std::string serialize() const = 0;
    virtual void display() const;

protected:
    std::string name;
    std::string type;
};

class FrontendTechnology : public Technology {
public:
    FrontendTechnology(const std::string& name, const std::string& framework);
    
    std::string serialize() const override;
    void display() const override;

private:
    std::string framework;
};

class BackendTechnology : public Technology {
public:
    BackendTechnology(const std::string& name, const std::string& language);
    
    void display() const override;
    std::string serialize() const override;

private:
    std::string language;
};

#endif // TECHNOLOGY_H
