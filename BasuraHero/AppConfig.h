#pragma once

namespace BasuraHero {

using namespace System;

public ref class AppConfig abstract sealed
{
public:
    static property String^ DbConnectionString {
        String^ get() {
            return "Data Source=(LocalDB)\\MSSQLLocalDB;Initial Catalog=BasuraHeroDB;Integrated Security=True";
        }
    }
};

}
