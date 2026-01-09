#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include <bits/stdc++.h>
#include "../models/Restaurant.h"
using namespace std;

// Singleton class to manage restaurants
class RestaurantManager {
    private:
        vector<Restaurant*> restaurants;
        static RestaurantManager* instance;

        RestaurantManager() { }

    public:
        static RestaurantManager* getInstance(){
            if(instance == nullptr){
                instance = new RestaurantManager();
            }
            return instance;
        }

        void addRestaurant(Restaurant* restaurant){
            restaurants.push_back(restaurant);
        }

        vector<Restaurant*> searchByLocation(const string& location) {
            vector<Restaurant*> results;

            string target = location;
            transform(target.begin(), target.end(), target.begin(),
                    [](unsigned char c) { return std::tolower(c); });

            for (auto* restaurant : restaurants) {
                string rl = restaurant->getLocation();
                transform(rl.begin(), rl.end(), rl.begin(),
                        [](unsigned char c) { return std::tolower(c); });

                if (rl == target) {
                    results.push_back(restaurant);
                }
            }

            return results;
        }

};

RestaurantManager* RestaurantManager::instance = nullptr;

#endif