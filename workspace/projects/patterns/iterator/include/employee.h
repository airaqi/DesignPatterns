#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__ 

class Employee
{
    public:
        Employee(const char* = "");
        virtual ~Employee();

        void name(const char* name);    const char* name() const;
        void age(int);                  int age() const;

    private:
        char _name[256];
        int _age;
};

#endif /* ifndef __EMPLOYEE_H__ */
