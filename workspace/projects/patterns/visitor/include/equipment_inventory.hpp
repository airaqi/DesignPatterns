#ifndef __EQUIPMENT_INVENTORY_H__
#define __EQUIPMENT_INVENTORY_H__ 

#include <ostream>
#include <string>
#include <unordered_map>

class Inventory
{
    public:
        Inventory();
        virtual ~Inventory();

        virtual void accumulate(std::string name);
        virtual double get(std::string name);
        virtual std::pmr::unordered_map<std::string, double>& getInventory();
        
        std::string to_string(std::string prefix = "");

        friend std::ostream& operator<<(std::ostream&,Inventory&);

    private:
        std::pmr::unordered_map<std::string, double> _inventory;
};

#endif /* ifndef __EQUIPMENT_INVENTORY_H__ */
