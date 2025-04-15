#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct SatelliteInfo {
    string launchDate;
    double launchMass;   // in kg
    double perigee;      // in km
    double apogee;       // in km
    double period;       // in minutes
    double inclination;  // in degrees
    bool isActive;
    string owner;        // Added for extra clarity (e.g., NOAA, NASA, CNES)
};

void printSatelliteInfo(const SatelliteInfo& sat) {
    cout << "Launch Date: " << sat.launchDate << endl;
    cout << "Launch Mass: " << sat.launchMass << " kg" << endl;
    cout << "Perigee Altitude: " << sat.perigee << " km" << endl;
    cout << "Apogee Altitude: " << sat.apogee << " km" << endl;
    cout << "Orbital Period: " << sat.period << " minutes" << endl;
    cout << "Inclination: " << sat.inclination << " degrees" << endl;
    cout << "Status: " << (sat.isActive ? "Active" : "Inactive") << endl;
    cout << "Owner: " << sat.owner << endl;
}

int main() {
    unordered_map<string, SatelliteInfo> satellites = {
        // NOAA POES
        {"NOAA-15", {"1998-05-13", 2230.0, 801.3, 816.9, 100.9, 98.5, true, "NOAA"}},
        {"NOAA-18", {"2005-05-20", 2232.0, 854.0, 870.0, 102.1, 98.74, true, "NOAA"}},
        {"NOAA-19", {"2009-02-06", 2232.0, 858.0, 870.0, 102.1, 99.2, true, "NOAA"}},

        // NOAA/NASA JPSS
        {"NOAA-20", {"2017-11-18", 2540.0, 824.0, 824.0, 101.4, 98.7, true, "NOAA/NASA"}},
        {"NOAA-21", {"2022-11-10", 2540.0, 824.0, 824.0, 101.4, 98.7, true, "NOAA/NASA"}},
        {"Suomi NPP", {"2011-10-28", 2150.0, 824.0, 824.0, 101.4, 98.7, true, "NOAA/NASA"}},

        // GOES Series
        {"GOES-14", {"2009-06-27", 3138.0, 35786.0, 35786.0, 1436.0, 0.0, false, "NOAA"}},
        {"GOES-16", {"2016-11-19", 5192.0, 35786.0, 35786.0, 1436.0, 0.0, true, "NOAA"}},
        {"GOES-17", {"2018-03-01", 5192.0, 35786.0, 35786.0, 1436.0, 0.0, false, "NOAA"}},
        {"GOES-18", {"2022-03-01", 5192.0, 35786.0, 35786.0, 1436.0, 0.0, true, "NOAA"}},
        {"GOES-19", {"2022-03-01", 5192.0, 35786.0, 35786.0, 1436.0, 0.0, true, "NOAA"}}, // aka GOES-T (placeholder)

        // DMSP
        {"DMSP-F16", {"2003-10-18", 1225.0, 833.0, 860.0, 101.9, 98.9, false, "US Air Force"}},
        {"DMSP-F17", {"2006-11-04", 1225.0, 833.0, 860.0, 101.9, 98.9, true, "US Air Force"}},
        {"DMSP-F19", {"2014-04-03", 1225.0, 833.0, 860.0, 101.9, 98.9, false, "US Air Force"}},

        // EWS-G
        {"EWS-G1", {"2006-05-24", 3138.0, 35786.0, 35786.0, 1436.0, 0.0, false, "US Air Force (formerly GOES-13)"}},
        {"EWS-G2", {"2010-03-04", 3138.0, 35786.0, 35786.0, 1436.0, 0.0, true, "US Air Force (formerly GOES-15)"}},

        // Jason-3
        {"Jason-3", {"2016-01-17", 553.0, 1336.0, 1336.0, 112.4, 66.0, true, "CNES"}},

        // DSCOVR
        {"DSCOVR", {"2015-02-11", 570.0, 187000.0, 187000.0, 525600.0, 0.0, true, "NOAA/NASA"}}
    };

    string input;
    cout << "Enter a satellite name (e.g., NOAA-20, GOES-16, DMSP-F17): ";
    getline(cin, input);

    if (satellites.find(input) != satellites.end()) {
        cout << "\n=== Satellite Information ===\n";
        printSatelliteInfo(satellites[input]);
    } else {
        cout << "Satellite not found. Please check the spelling or try another one.\n";
    }

    return 0;
}
