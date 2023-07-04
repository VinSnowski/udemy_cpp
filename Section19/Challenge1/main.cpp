// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City
{
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country
{
    std::string name;
    std::vector<City> cities;
};

struct Tours
{
    std::string title;
    std::vector<Country> countries;
};

void display_centered(std::string text, int size = 80)
{
    std::cout << std::setw((size - static_cast<double>(text.size())) / 2) << std::right << std::setfill(' ') << "";
    std::cout << text << std::setw((45 - static_cast<double>(text.size())) / 2) << std::left << std::setfill(' ') << "";
    std::cout << std::endl;
}

void display_ruler(int size = 80)
{
    for (int i = 0; i < size; i++)
        std::cout << i % 10;
    std::cout << std::endl;
}

void display_in_four_sections(std::string field1, std::string field2, std::string field3, std::string field4, int size)
{
    std::cout << std::setprecision(2) << std::fixed;
    int f1_size = size / 4;
    int f2_size = size / 3;
    int f3_size = size - field4.size() - f1_size - f2_size;
    std::cout << std::setw(f1_size) << std::left << std::setfill(' ') << field1;
    std::cout << std::setw(f2_size) << std::left << std::setfill(' ') << field2;
    std::cout << std::setw(f3_size) << std::left << std::setfill(' ') << field3;
    std::cout << field4 << std::endl;
}

void display_column_headers(int size = 80)
{
    display_in_four_sections("Country", "City", "Population", "Price", size);
}

void display_line(char fill_char = ' ', int size = 80)
{
    std::cout << std::setw(size) << std::setfill(fill_char) << "" << std::endl;
}

int main()
{
    Tours tours{"Tour Ticket Prices from Miami",
                {
                    {
                        "Colombia",
                        {{"Bogota", 8778000, 400.98},
                         {"Cali", 2401000, 424.12},
                         {"Medellin", 2464000, 350.98},
                         {"Cartagena", 972000, 345.34}},
                    },
                    {
                        "Brazil",
                        {{"Rio De Janiero", 13500000, 567.45},
                         {"Sao Paulo", 11310000, 975.45},
                         {"Salvador", 18234000, 855.99}},
                    },
                    {
                        "Chile",
                        {{"Valdivia", 260000, 569.12},
                         {"Santiago", 7040000, 520.00}},
                    },
                    {"Argentina", {{"Buenos Aires", 3010000, 723.77}}},
                }};
    display_line();
    display_ruler();
    display_line();
    display_centered(tours.title);
    display_line();
    display_column_headers();
    display_line('-');

    std::cout << std::setprecision(2) << std::fixed;

    for (auto country : tours.countries)
    {
        display_in_four_sections(country.name,
                                 country.cities[0].name,
                                 std::to_string(country.cities[0].population),
                                 std::to_string(country.cities[0].cost), 80);
        for (auto city : std::vector<City>(country.cities.begin() + 1, country.cities.end()))
        {
            display_in_four_sections("",
                                     city.name,
                                     std::to_string(city.population),
                                     std::to_string(city.cost), 80);
        }
    }

    return 0;
}

// len(text)
//         x
//     + text + y = 90
