#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H
#include <string>

class Technology {
protected:
    std::string name;
    std::string type;

public:
    Technology(const std::string& name, const std::string& type);
    virtual ~Technology() = default;
    virtual void dispay() const;
    virtual std::string serialize() const = 0;
};

class FrontentTechnology : public Technology {
private:
    std::string framework;

public:
    FrontentTechnology(const std::string& name, const std::string& framework);
    void display() const override;
    std::string serialize() const override;
};

class BackendTechnology : public Technology {
private:
    std::string language;

public:
    BackendTechnology(const std::string& name, const std::string& language);
    voif dispay() const override;
    std::string serialize() const override;
};

#endif // TECHNOLOGY_H