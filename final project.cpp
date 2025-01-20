#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <climits>
#include <fstream>
#include <tuple> // Added this line for reverse function
#include <map>
#include <thread>
#include <chrono>
#include <ctime>
#include <limits>
#include <iomanip>

using namespace std;
int trafficDensity = 0;
int temperature = 25; // Starting temperature in Celsius
int humidity = 50;    // Percentage of humidity
int pollutionLevel = 20; // Pollution level in percentage
string weatherCondition = "Clear";

// Function definitions

enum TrafficCondition


 {
    LIGHT,

    MODERATE,

    HEAVY
};

// Class to represent a graph for the city traffic network
/*function Dijkstra(graph, source, destination):

    distances = {node: INFINITY for each node in graph}
    distances[source] = 0


    previous = {}
    priorityQueue = PriorityQueue()

    priorityQueue.push((0, source))



    while priorityQueue is not empty:

        (currentDistance, currentNode) = priorityQueue.pop()

        if currentDistance > distances[currentNode]:
            continue

        for each neighbor in graph[currentNode]:

            newDistance = currentDistance + edgeWeight(currentNode, neighbor)
            if newDistance < distances[neighbor]:


                distances[neighbor] = newDistance
                previous[neighbor] = currentNode
                priorityQueue.push((newDistance, neighbor))


    if distances[destination] == INFINITY:
        return "No path exists"

    path = []
    while
        destination exists in previous:
        path.insert(0, destination)
        destination = previous[destination]
         path.insert(0, source)

    return path, distances[destination]*/


  /*  City Connectivity System
1. Select City
2. Exit
Enter your choice: 1
Available Cities:
- Gulbarga
- Gadag
- Tumkur
- Mysore
- Hassan
- Bangalore
- Belagavi
- Raichur
- Mandya
- Vijaypur
- Udupi
- Dharwad
- Pune
- Shivamogga
- Hubballi
- Bagalkot*/
// Main function
// Enum for traffic conditions

class CityGraph

 {
private:


    unordered_map<string, vector<pair<string, pair<int, TrafficCondition>>>> adjList;

public:


    public:

    // Pre-add some locations and roads to the city
    CityGraph()

    {
        // Predefined edges with traffic conditions


     addEdge("Sampige Nagar", "Shivaji Nagar", 5, LIGHT);
       addEdge("Sampige Nagar", "Udyambag", 7, MODERATE);

addEdge("Sampige Nagar", "Tilakwadi", 4, LIGHT);
addEdge("Tilakwadi", "Kakti", 6, MODERATE);
addEdge("Tilakwadi", "Angol", 8, HEAVY);


addEdge("Udyambag", "Vadgaon", 5, LIGHT);
addEdge("Udyambag", "Camp", 4, LIGHT);

addEdge("Vadgaon", "RPD Cross", 3, LIGHT);
addEdge("RPD Cross", "Hindwadi", 5, MODERATE);

addEdge("Hindwadi", "Bogarves", 6, HEAVY);

addEdge("Bogarves", "Jamboti", 8, MODERATE);
addEdge("Jamboti", "Bailhongal", 12, LIGHT);

addEdge("Bailhongal", "Gokak", 18, HEAVY);
addEdge("Gokak", "Kudachi", 10, MODERATE);

addEdge("Kudachi", "Hukkeri", 15, LIGHT);

addEdge("Hukkeri", "Mudalagi", 10, MODERATE);

addEdge("Mudalagi", "Raibag", 7, LIGHT);
addEdge("Raibag", "Chikkodi", 13, HEAVY);
addEdge("Chikkodi", "Bhimgad", 8, MODERATE);

addEdge("Bhimgad", "Sulebhavi", 12, LIGHT);


    addEdge("Gulbarga City Center", "Aland", 40, LIGHT);
addEdge("Gulbarga City Center", "Chittapur", 55, MODERATE);
addEdge("Gulbarga City Center", "Sedam", 65, HEAVY);

addEdge("Gulbarga City Center", "Shahabad", 30, LIGHT);
addEdge("Gulbarga City Center", "Afzalpur", 45, MODERATE);

addEdge("Gulbarga City Center", "Jevargi", 50, LIGHT);
addEdge("Aland", "Humnabad", 50, LIGHT);

addEdge("Humnabad", "Bidar", 60, HEAVY);
addEdge("Bidar", "Basavakalyan", 70, MODERATE);

addEdge("Basavakalyan", "Bhalki", 40, LIGHT);
addEdge("Chittapur", "Malkhed", 20, MODERATE);

addEdge("Malkhed", "Sedam", 25, LIGHT);
addEdge("Sedam", "Kodangal", 35, LIGHT);

addEdge("Kodangal", "Tandur", 20, MODERATE);
addEdge("Tandur", "Vikarabad", 30, LIGHT);

addEdge("Vikarabad", "Hyderabad", 90, HEAVY);
addEdge("Shahabad", "Yadgir", 50, MODERATE);

addEdge("Yadgir", "Surpur", 60, LIGHT);
addEdge("Surpur", "Shorapur", 40, HEAVY);

addEdge("Shorapur", "Lingsugur", 50, MODERATE);
addEdge("Hassan City Center", "Arsikere", 35, LIGHT);

addEdge("Hassan City Center", "Alur", 45, LIGHT);
addEdge("Arsikere", "Chikmagalur", 50, MODERATE);

addEdge("Alur", "Belur", 30, LIGHT);
addEdge("Belur", "Mysore", 55, HEAVY);

addEdge("Chikmagalur", "Mudigere", 30, MODERATE);
addEdge("Mudigere", "Bengaluru", 220, HEAVY);

addEdge("Mysore City Center", "Hunsur", 30, LIGHT);
addEdge("Mysore City Center", "Nanjangud", 25, LIGHT);

addEdge("Nanjangud", "Chamarajanagar", 40, MODERATE);
addEdge("Hunsur", "Piriyapatna", 45, LIGHT);

addEdge("Piriyapatna", "Madikeri", 55, HEAVY);
addEdge("Madikeri", "Virajpet", 60, MODERATE);

addEdge("Virajpet", "Mysore", 70, LIGHT);
addEdge("Mysore", "Bengaluru", 140, HEAVY);

addEdge("Tumkur City Center", "Kunigal", 30, LIGHT);
addEdge("Tumkur City Center", "Tiptur", 50, MODERATE);

addEdge("Kunigal", "Magadi", 20, LIGHT);
addEdge("Magadi", "Bengaluru", 60, HEAVY);

addEdge("Tiptur", "Madhugiri", 40, LIGHT);
addEdge("Madhugiri", "Tumkur", 20, MODERATE);

addEdge("Tiptur", "Arsikere", 35, LIGHT);
addEdge("Arsikere", "Hassan", 55, HEAVY);

addEdge("Gadag City Center", "Bagalkot", 70, MODERATE);
addEdge("Gadag City Center", "Ron", 40, LIGHT);

addEdge("Ron", "Dambal", 20, MODERATE);
addEdge("Dambal", "Hubli", 55, HEAVY);

addEdge("Hubli", "Gadag", 50, LIGHT);
addEdge("Gadag", "Laxmeshwar", 35, LIGHT);

addEdge("Laxmeshwar", "Kundgol", 15, LIGHT);
addEdge("Kundgol", "Bagalkot", 60, MODERATE);

addEdge("Bagalkot", "Hubli", 120, HEAVY);
addEdge("Bagalkot", "Bijapur", 85, LIGHT);

addEdge("Bagalkot", "Badami", 30, MODERATE);
addEdge("Bagalkot", "Bailhongal", 45, LIGHT);

addEdge("Bagalkot", "Gokak", 70, MODERATE);
addEdge("Bagalkot", "Athani", 60, HEAVY);

addEdge("Bagalkot", "Kalaburagi", 120, LIGHT);
addEdge("Bagalkot", "Sindagi", 40, MODERATE);

addEdge("Bagalkot", "Raichur", 90, HEAVY);
addEdge("Bagalkot", "Hubballi", 100, LIGHT);

addEdge("Bagalkot", "Chitradurga", 150, MODERATE);
addEdge("Bagalkot", "Davangere", 100, LIGHT);
addEdge("Bagalkot", "Yadgir", 80, HEAVY);

addEdge("Bagalkot", "Gulbarga", 130, LIGHT);
addEdge("Bagalkot", "Haveri", 140, MODERATE);

addEdge("Bagalkot", "Vijayapur", 70, LIGHT);
addEdge("Bagalkot", "Belagavi", 60, MODERATE);

addEdge("Bagalkot", "Mysore", 180, HEAVY);
addEdge("Bagalkot", "Bengaluru", 200, LIGHT);

addEdge("Bagalkot", "Kalaburagi", 110, MODERATE);
addEdge("Bagalkot", "Hassan", 160, LIGHT);

addEdge("Bagalkot", "Shivamogga", 220, HEAVY);
addEdge("Bagalkot", "Raichur City Center", 90, MODERATE);

addEdge("Bagalkot", "Mangaluru", 210, LIGHT);
addEdge("Bagalkot", "Chikkamagaluru", 190, MODERATE);

addEdge("Bagalkot", "Dharwad", 120, LIGHT);
addEdge("Bagalkot", "Koppal", 60, HEAVY);

addEdge("Bagalkot", "Pune", 230, MODERATE);
addEdge("Bagalkot", "Siddapura", 100, LIGHT);

addEdge("Bagalkot", "Challakere", 110, MODERATE);
addEdge("Bagalkot", "Mandya", 170, HEAVY);

addEdge("Bagalkot", "Raichur", 130, MODERATE);
addEdge("Bagalkot", "Hubbali", 100, LIGHT);

addEdge("Bagalkot", "Bengaluru", 200, MODERATE);
addEdge("Bagalkot", "Vijayapur", 60, HEAVY);

addEdge("Bagalkot", "Gokak", 40, LIGHT);
addEdge("Bagalkot", "Shivaji Nagar", 150, LIGHT);

addEdge("Bagalkot", "Davangere", 180, MODERATE);
addEdge("Bagalkot", "Pune", 220, HEAVY);

addEdge("Bagalkot", "Terdal", 50, MODERATE);
addEdge("Bagalkot", "Bengaluru", 210, LIGHT);

addEdge("Bagalkot", "Bagalkot City", 30, LIGHT);
addEdge("Mysore", "Hassan", 35, LIGHT);

addEdge("Mysore", "Bengaluru", 150, HEAVY);
addEdge("Mysore", "Channarayapatna", 40, MODERATE);

addEdge("Mysore", "Nanjangud", 25, LIGHT);
addEdge("Mysore", "Mandya", 50, MODERATE);

addEdge("Mysore", "T Narasipura", 60, LIGHT);
addEdge("Mysore", "Kollegal", 80, HEAVY);

addEdge("Mysore", "Srirangapatna", 30, LIGHT);
addEdge("Mysore", "Gundlupet", 85, MODERATE);

addEdge("Mysore", "Chamarajanagar", 95, HEAVY);
addEdge("Mysore", "Heggadadevankote", 70, MODERATE);

addEdge("Mysore", "Periyapatna", 55, LIGHT);
addEdge("Mysore", "Bilikere", 40, MODERATE);

addEdge("Mysore", "Siddarthanagar", 15, LIGHT);
addEdge("Mysore", "KR Nagar", 50, LIGHT);

addEdge("Mysore", "Hunsur", 60, HEAVY);
addEdge("Mysore", "Kushalnagar", 90, MODERATE);

addEdge("Mysore", "Nagamangala", 70, LIGHT);
addEdge("Mysore", "Yelwal", 35, MODERATE);

addEdge("Mysore", "KRS", 40, LIGHT);
addEdge("Mysore", "Jayapura", 45, LIGHT);

addEdge("Mysore", "Hebbal", 30, MODERATE);
addEdge("Mysore", "Mysuru City Center", 0, LIGHT);

addEdge("Mysore", "Srirangapatna", 35, LIGHT);
addEdge("Mysore", "Chamundeshwari Hills", 25, LIGHT);

addEdge("Mysore", "Gokulam", 10, LIGHT);
addEdge("Mysore", "RM Nagar", 50, MODERATE);

addEdge("Mysore", "Vijayanagar", 30, MODERATE);
addEdge("Mysore", "Yadavagiri", 40, LIGHT);

addEdge("Mysore", "T Narasipura", 60, LIGHT);
addEdge("Mysore", "Mysore Airport", 45, MODERATE);

addEdge("Mysore", "Kuvempunagar", 25, LIGHT);
addEdge("Mysore", "Metagalli", 35, HEAVY);

addEdge("Mysore", "Vontikoppal", 30, LIGHT);
addEdge("Mysore", "Mandi Mohalla", 15, LIGHT);

addEdge("Mysore", "Ravindra Nagar", 20, MODERATE);
addEdge("Mysore", "Paduvarahalli", 50, LIGHT);

addEdge("Mysore", "Aloka Sadan", 40, MODERATE);
addEdge("Mysore", "Nazarbad", 25, LIGHT);

addEdge("Mysore", "Aloysius", 30, MODERATE);
addEdge("Mysore", "Shanthinagar", 20, LIGHT);

addEdge("Mysore", "Mysuru Zoo", 10, LIGHT);
addEdge("Mysore", "Bannimantap", 20, LIGHT);

addEdge("Mysore", "Bharath Nagar", 25, MODERATE);
addEdge("Mysore", "Saraswathipuram", 30, LIGHT);

addEdge("Mysore", "Rajiv Nagar", 35, MODERATE);
addEdge("Mysore", "Hootagalli", 50, HEAVY);

addEdge("Tumkur", "Kunigal", 20, LIGHT);
addEdge("Tumkur", "Sira", 40, MODERATE);
addEdge("Tumkur", "Pavagada", 45, LIGHT);

addEdge("Tumkur", "Koratagere", 30, LIGHT);
addEdge("Tumkur", "Tiptur", 50, HEAVY);

addEdge("Tumkur", "Chikkanayakanahalli", 35, LIGHT);
addEdge("Tumkur", "Gubbi", 25, LIGHT);

addEdge("Tumkur", "Udupi", 125, HEAVY);
addEdge("Tumkur", "Bengaluru", 75, LIGHT);

addEdge("Tumkur", "Madhugiri", 40, MODERATE);
addEdge("Tumkur", "Channarayapatna", 60, MODERATE);

addEdge("Tumkur", "Magadi", 55, LIGHT);
addEdge("Tumkur", "Hassan", 100, HEAVY);

addEdge("Tumkur", "Davanagere", 115, LIGHT);
addEdge("Tumkur", "Anekal", 85, MODERATE);

addEdge("Tumkur", "Nelamangala", 70, LIGHT);
addEdge("Tumkur", "Nellore", 160, HEAVY);

addEdge("Tumkur", "Bagalkot", 200, HEAVY);
addEdge("Tumkur", "Bidar", 230, LIGHT);

addEdge("Tumkur", "Vijayapura", 150, HEAVY);
addEdge("Tumkur", "Raichur", 190, LIGHT);

addEdge("Tumkur", "Hubballi", 200, HEAVY);
addEdge("Tumkur", "Haveri", 120, LIGHT);

addEdge("Tumkur", "Chitradurga", 80, LIGHT);
addEdge("Tumkur", "Bengaluru", 65, LIGHT);

addEdge("Tumkur", "Sira", 40, MODERATE);
addEdge("Tumkur", "Gubbi", 35, MODERATE);

addEdge("Tumkur", "Malur", 70, MODERATE);
addEdge("Tumkur", "Kolar", 85, LIGHT);

addEdge("Tumkur", "Kundgol", 90, LIGHT);
addEdge("Tumkur", "Bagepalli", 40, LIGHT);

addEdge("Tumkur", "Ramnagaram", 95, MODERATE);
addEdge("Tumkur", "Hunsur", 70, HEAVY);

addEdge("Tumkur", "Shivamogga", 125, MODERATE);
addEdge("Tumkur", "Kodagu", 150, LIGHT);

addEdge("Tumkur", "Yadgir", 130, LIGHT);
addEdge("Tumkur", "Koppal", 140, HEAVY);

addEdge("Hassan", "Channarayapatna", 25, LIGHT);
addEdge("Hassan", "Hulikere", 20, LIGHT);

addEdge("Hassan", "Alur", 35, LIGHT);
addEdge("Hassan", "Belur", 40, MODERATE);

addEdge("Hassan", "Arasikere", 50, LIGHT);
addEdge("Hassan", "Holenarasipura", 55, LIGHT);

addEdge("Hassan", "Bangalore", 180, HEAVY);
addEdge("Hassan", "Mysore", 90, HEAVY);

addEdge("Hassan", "Sakleshpur", 45, LIGHT);
addEdge("Hassan", "Chikmagalur", 80, MODERATE);

addEdge("Hassan", "Mudigere", 65, LIGHT);
addEdge("Hassan", "Bantwal", 115, HEAVY);

addEdge("Hassan", "Nagamangala", 60, LIGHT);
addEdge("Hassan", "Kodagu", 120, MODERATE);

addEdge("Hassan", "Gundlupet", 95, LIGHT);
addEdge("Hassan", "T Narasipura", 75, MODERATE);

addEdge("Hassan", "Mandya", 60, MODERATE);
addEdge("Hassan", "Yelandur", 50, LIGHT);

addEdge("Hassan", "Hunsur", 85, LIGHT);
addEdge("Hassan", "KR Nagar", 40, LIGHT);

addEdge("Hassan", "Krishnarajpet", 55, MODERATE);
addEdge("Hassan", "Haradanahalli", 35, MODERATE);

addEdge("Hassan", "Siddapura", 45, LIGHT);
addEdge("Hassan", "Biligiri", 90, LIGHT);

addEdge("Hassan", "Ramanagaram", 135, HEAVY);

addEdge("Hassan", "Tumkur", 110, LIGHT);
addEdge("Hassan", "Channarayapatna", 20, LIGHT);

addEdge("Hassan", "Madhugiri", 120, MODERATE);
addEdge("Hassan", "Koppal", 160, HEAVY);

addEdge("Hassan", "Bidar", 200, LIGHT);
addEdge("Hassan", "Bagepalli", 85, LIGHT);

addEdge("Hassan", "Yadgir", 175, HEAVY);
addEdge("Hassan", "Davanagere", 180, MODERATE);
addEdge("Hassan", "Chikkanayakanahalli", 40, LIGHT);

addEdge("Hassan", "Nagapattinam", 210, HEAVY);
addEdge("Hassan", "Kolar", 150, LIGHT);

addEdge("Hassan", "Bengaluru", 180, LIGHT);
addEdge("Hassan", "Srirangapatna", 60, MODERATE);

addEdge("Hassan", "Mysuru", 85, LIGHT);
addEdge("Hassan", "Kodagu", 130, LIGHT);

addEdge("Hassan", "Bangalore City Center", 190, HEAVY);
addEdge("Hassan", "Gonikoppal", 120, LIGHT);

addEdge("Hassan", "Periyapatna", 55, LIGHT);
addEdge("Hassan", "T Narasipura", 95, MODERATE);

addEdge("Hassan", "Ravindra Nagar", 40, MODERATE);
addEdge("Hassan", "Shanthinagar", 50, LIGHT);

addEdge("Hassan", "Chamundeshwari", 65, LIGHT);
addEdge("Hassan", "Mysore Road", 90, LIGHT);

addEdge("Hassan", "Kushalnagar", 110, LIGHT);
addEdge("Hassan", "Kuvempunagar", 75, LIGHT);

addEdge("Hassan", "Bannimantap", 85, LIGHT);

addEdge("Hassan", "Yelwal", 95, MODERATE);
addEdge("Hassan", "Siddarthanagar", 30, LIGHT);

addEdge("Bengaluru", "Yelahanka", 20, LIGHT);
addEdge("Bengaluru", "Koramangala", 15, LIGHT);

addEdge("Bengaluru", "Indiranagar", 10, LIGHT);
addEdge("Bengaluru", "Malleswaram", 15, LIGHT);

addEdge("Bengaluru", "Whitefield", 25, MODERATE);
addEdge("Bengaluru", "Marathahalli", 20, LIGHT);

addEdge("Bengaluru", "Banaswadi", 15, LIGHT);
addEdge("Bengaluru", "Jayanagar", 10, LIGHT);

addEdge("Bengaluru", "Banashankari", 15, LIGHT);
addEdge("Bengaluru", "Hebbal", 20, LIGHT);

addEdge("Bengaluru", "Hennur", 20, LIGHT);
addEdge("Bengaluru", "Kalyan Nagar", 15, LIGHT);

addEdge("Bengaluru", "Electronic City", 30, MODERATE);
addEdge("Bengaluru", "Vijayanagar", 10, LIGHT);
addEdge("Bengaluru", "Kengeri", 25, LIGHT);

addEdge("Bengaluru", "JP Nagar", 10, LIGHT);
addEdge("Bengaluru", "Shivaji Nagar", 5, LIGHT);

addEdge("Bengaluru", "Seshadripuram", 5, LIGHT);
addEdge("Bengaluru", "Rajajinagar", 10, LIGHT);

addEdge("Bengaluru", "Sadashivanagar", 15, LIGHT);
addEdge("Bengaluru", "Ulsoor", 10, LIGHT);
addEdge("Bengaluru", "Kumara Park", 15, LIGHT);

addEdge("Bengaluru", "Frazer Town", 10, LIGHT);
addEdge("Bengaluru", "Jeevan Bhima Nagar", 15, LIGHT);

addEdge("Bengaluru", "Gubbalala", 20, LIGHT);
addEdge("Bengaluru", "Basavanagudi", 10, LIGHT);

addEdge("Bengaluru", "Nandi Hills", 45, LIGHT);
addEdge("Bengaluru", "Rajapura", 30, LIGHT);

addEdge("Bengaluru", "Benniganahalli", 25, LIGHT);
addEdge("Bengaluru", "Yeshwanthpur", 15, LIGHT);

addEdge("Bengaluru", "Bommanahalli", 20, LIGHT);
addEdge("Bengaluru", "Hosur Road", 35, HEAVY);

addEdge("Bengaluru", "Bangalore Palace", 10, LIGHT);
addEdge("Bengaluru", "Kudlu", 25, LIGHT);

addEdge("Bengaluru", "BTM Layout", 10, LIGHT);
addEdge("Bengaluru", "Bellandur", 30, LIGHT);

addEdge("Bengaluru", "Koramangala 4th Block", 10, LIGHT);
addEdge("Bengaluru", "Sarjapur", 30, MODERATE);

addEdge("Bengaluru", "Peenya", 20, LIGHT);
addEdge("Bengaluru", "Malleshwaram West", 10, LIGHT);

addEdge("Bengaluru", "Varthur", 25, LIGHT);
addEdge("Bengaluru", "Channasandra", 20, LIGHT);

addEdge("Bengaluru", "Hegde Nagar", 20, LIGHT);
addEdge("Bengaluru", "Ramagondanahalli", 25, LIGHT);

addEdge("Bengaluru", "BTM 2nd Stage", 15, LIGHT);
addEdge("Bengaluru", "Sarakki", 25, LIGHT);

addEdge("Bengaluru", "Bangalore East", 20, LIGHT);
addEdge("Bengaluru", "Kotturpuram", 20, LIGHT);

addEdge("Bengaluru", "Chandapura", 30, LIGHT);
addEdge("Bengaluru", "Vijayanagar 2nd Stage", 15, LIGHT);
addEdge("Mandya", "Srirangapatna", 15, LIGHT);

addEdge("Mandya", "Maddur", 20, LIGHT);
addEdge("Mandya", "Nagamangala", 25, LIGHT);

addEdge("Mandya", "Pandavapura", 18, LIGHT);
addEdge("Mandya", "Krishna Raja Sagara", 20, LIGHT);
addEdge("Mandya", "Mysuru Road", 40, MODERATE);

addEdge("Mandya", "Belakavadi", 30, LIGHT);
addEdge("Mandya", "Bhadravati", 50, LIGHT);

addEdge("Mandya", "Kikkeri", 25, LIGHT);
addEdge("Mandya", "Ramanagaram", 40, MODERATE);
addEdge("Mandya", "Channarayapatna", 35, LIGHT);

addEdge("Mandya", "Bannur", 22, LIGHT);
addEdge("Mandya", "Heggadde", 28, LIGHT);

addEdge("Mandya", "Hosakere", 30, LIGHT);
addEdge("Mandya", "Malavalli", 40, LIGHT);

addEdge("Mandya", "Gundlupet", 50, LIGHT);
addEdge("Mandya", "Shivapura", 35, LIGHT);

addEdge("Mandya", "Mysuru City", 45, LIGHT);
addEdge("Mandya", "Sathagalu", 30, LIGHT);

addEdge("Mandya", "Somwarpet", 60, LIGHT);
addEdge("Mandya", "Channapatna", 35, LIGHT);

addEdge("Mandya", "Hunsur", 55, LIGHT);
addEdge("Mandya", "Pavagada", 70, LIGHT);

addEdge("Mandya", "Doddaballapura", 45, LIGHT);
addEdge("Mandya", "Mangalore Road", 50, MODERATE);

addEdge("Mandya", "Kengeri", 60, MODERATE);
addEdge("Mandya", "Chikkanayakanahalli", 50, LIGHT);

addEdge("Mandya", "Vijayanagar", 30, LIGHT);
addEdge("Mandya", "Magadi", 65, LIGHT);

addEdge("Mandya", "Rajapura", 55, LIGHT);
addEdge("Mandya", "Hosa Road", 45, LIGHT);

addEdge("Mandya", "Yelachahalli", 40, LIGHT);
addEdge("Mandya", "Bettadasanapura", 50, LIGHT);

addEdge("Mandya", "Nidaghatta", 30, LIGHT);
addEdge("Mandya", "Hosakote", 55, LIGHT);
addEdge("Mandya", "Kanakapura", 50, LIGHT);

addEdge("Mandya", "Hoskote", 60, LIGHT);
addEdge("Mandya", "Bidadi", 70, LIGHT);
addEdge("Mandya", "Hosur", 100, LIGHT);

addEdge("Mandya", "Kolar", 85, LIGHT);
addEdge("Mandya", "Tiptur", 75, LIGHT);

addEdge("Mandya", "Magadi Road", 50, LIGHT);
addEdge("Mandya", "Yelahanka", 90, MODERATE);

addEdge("Mandya", "Koramangala", 95, LIGHT);
addEdge("Mandya", "Jayanagar", 80, LIGHT);
addEdge("Mandya", "Banashankari", 85, LIGHT);

addEdge("Mandya", "Whitefield", 110, LIGHT);
addEdge("Mandya", "Vishweshwarapuram", 65, LIGHT);
addEdge("Mandya", "KR Puram", 95, LIGHT);


addEdge("Raichur", "Sindhanur", 50, LIGHT);
addEdge("Raichur", "Manvi", 40, LIGHT);

addEdge("Raichur", "Lingasugur", 60, LIGHT);
addEdge("Raichur", "Raichur City Center", 10, LIGHT);
addEdge("Raichur", "Deodurga", 50, LIGHT);

addEdge("Raichur", "Shahapur", 45, LIGHT);
addEdge("Raichur", "Yadgir", 70, LIGHT);
addEdge("Raichur", "Raichur Fort", 15, LIGHT);

addEdge("Raichur", "Bagad", 60, LIGHT);
addEdge("Raichur", "Raichur Airport", 30, LIGHT);
addEdge("Raichur", "Almala", 50, LIGHT);

addEdge("Raichur", "Srinivaspur", 80, LIGHT);
addEdge("Raichur", "Devdurga", 60, LIGHT);
addEdge("Raichur", "Kodambur", 40, LIGHT);

addEdge("Raichur", "Hatti", 55, LIGHT);
addEdge("Raichur", "Bodhan", 75, LIGHT);
addEdge("Raichur", "Shorapur", 65, LIGHT);

addEdge("Raichur", "Kustagi", 45, LIGHT);
addEdge("Raichur", "Raichur Junction", 20, LIGHT);
addEdge("Raichur", "Peddur", 50, LIGHT);

addEdge("Raichur", "Sangapur", 45, LIGHT);
addEdge("Raichur", "Jangama", 50, LIGHT);
addEdge("Raichur", "Malkapur", 60, LIGHT);

addEdge("Raichur", "Dharwad", 90, LIGHT);
addEdge("Raichur", "Bangalore", 160, LIGHT);

addEdge("Raichur", "Yadgir City", 70, LIGHT);
addEdge("Raichur", "Jevargi", 50, LIGHT);

addEdge("Raichur", "Koppal", 80, LIGHT);

addEdge("Raichur", "Bagalkot", 100, LIGHT);

addEdge("Raichur", "Karnataka Soudha", 20, LIGHT);
addEdge("Raichur", "Chandrapur", 45, LIGHT);

addEdge("Raichur", "Shivana Halli", 50, LIGHT);
addEdge("Raichur", "Somanhalli", 30, LIGHT);

addEdge("Raichur", "Dundalli", 60, LIGHT);
addEdge("Raichur", "Aminabad", 45, LIGHT);

addEdge("Raichur", "Pachapur", 55, LIGHT);
addEdge("Raichur", "Husainabad", 60, LIGHT);

addEdge("Raichur", "Sarpan", 70, LIGHT);
addEdge("Raichur", "Boganahalli", 50, LIGHT);

addEdge("Raichur", "Akkalapur", 45, LIGHT);
addEdge("Raichur", "Raichur Town", 25, LIGHT);

addEdge("Raichur", "Karnataka Nagar", 50, LIGHT);
addEdge("Hubballi", "Dharwad", 20, LIGHT);

addEdge("Hubballi", "Koppal", 70, LIGHT);

addEdge("Hubballi", "Bagalkot", 100, LIGHT);
addEdge("Hubballi", "Gadag", 50, LIGHT);

addEdge("Hubballi", "Ranebennur", 35, LIGHT);
addEdge("Hubballi", "Hubballi City Center", 10, LIGHT);

addEdge("Hubballi", "Hubballi Bypass", 15, LIGHT);
addEdge("Hubballi", "Haveri", 85, LIGHT);

addEdge("Hubballi", "Shivamogga", 130, LIGHT);
addEdge("Hubballi", "Bangalore", 350, LIGHT);

addEdge("Hubballi", "Mysore", 300, LIGHT);
addEdge("Hubballi", "Belagavi", 105, LIGHT);

addEdge("Hubballi", "Bijapur", 145, LIGHT);
addEdge("Hubballi", "Bagalkot", 85, LIGHT);

addEdge("Hubballi", "Hubballi Junction", 20, LIGHT);
addEdge("Hubballi", "Hospet", 85, LIGHT);

addEdge("Hubballi", "Sadalga", 50, LIGHT);
addEdge("Hubballi", "Kadur", 125, LIGHT);

addEdge("Hubballi", "Gokak", 70, LIGHT);
addEdge("Hubballi", "Hampi", 75, LIGHT);

addEdge("Hubballi", "Yaragatti", 60, LIGHT);
addEdge("Hubballi", "Raichur", 180, LIGHT);

addEdge("Hubballi", "Chitradurga", 150, LIGHT);
addEdge("Hubballi", "Bagalkot", 90, LIGHT);

addEdge("Hubballi", "Sivapur", 50, LIGHT);
addEdge("Hubballi", "Dharwad City Center", 25, LIGHT);

addEdge("Hubballi", "Lingsugur", 160, LIGHT);
addEdge("Hubballi", "Koppal City Center", 85, LIGHT);

addEdge("Hubballi", "Gadag City Center", 55, LIGHT);
addEdge("Hubballi", "Mysore City Center", 300, LIGHT);
addEdge("Hubballi", "Raichur City Center", 170, LIGHT);

addEdge("Hubballi", "Haveri City Center", 80, LIGHT);
addEdge("Hubballi", "Challakere", 140, LIGHT);

addEdge("Hubballi", "Hampi Ruins", 85, LIGHT);
addEdge("Hubballi", "Bangalore Bypass", 350, LIGHT);

addEdge("Hubballi", "Kadur", 120, LIGHT);
addEdge("Hubballi", "Gokak", 75, LIGHT);

addEdge("Hubballi", "Mudalgi", 100, LIGHT);
addEdge("Hubballi", "Sindhanur", 175, LIGHT);

addEdge("Hubballi", "Sadar Bazar", 20, LIGHT);
addEdge("Hubballi", "Hampi Bypass", 70, LIGHT);

addEdge("Hubballi", "Bagalkot City Center", 95, LIGHT);
addEdge("Hubballi", "Savagundhi", 40, LIGHT);

addEdge("Hubballi", "Talikoti", 110, LIGHT);

addEdge("Hubballi", "Kudligi", 75, LIGHT);
addEdge("Hubballi", "Hubballi Urban", 25, LIGHT);

addEdge("Hubballi", "Gadag Urban", 60, LIGHT);

addEdge("Dharwad", "Hubballi", 20, LIGHT);
addEdge("Dharwad", "Kadur", 80, LIGHT);

addEdge("Dharwad", "Gadag", 60, LIGHT);
addEdge("Dharwad", "Bagalkot", 90, LIGHT);

addEdge("Dharwad", "Haveri", 75, LIGHT);
addEdge("Dharwad", "Belagavi", 120, LIGHT);

addEdge("Dharwad", "Bijapur", 150, LIGHT);
addEdge("Dharwad", "Sivapur", 100, LIGHT);

addEdge("Dharwad", "Raichur", 180, LIGHT);
addEdge("Dharwad", "Shivamogga", 170, LIGHT);

addEdge("Dharwad", "Mysore", 280, LIGHT);
addEdge("Dharwad", "Bangalore", 320, LIGHT);

addEdge("Dharwad", "Chitradurga", 150, LIGHT);
addEdge("Dharwad", "Hospet", 110, LIGHT);

addEdge("Dharwad", "Yaragatti", 85, LIGHT);
addEdge("Dharwad", "Gokak", 100, LIGHT);

addEdge("Dharwad", "Hampi", 120, LIGHT);
addEdge("Dharwad", "Lingsugur", 170, LIGHT);

addEdge("Dharwad", "Sadar Bazar", 20, LIGHT);
addEdge("Dharwad", "Raichur City Center", 175, LIGHT);

addEdge("Dharwad", "Gadag City Center", 60, LIGHT);
addEdge("Dharwad", "Bagalkot City Center", 95, LIGHT);

addEdge("Dharwad", "Haveri City Center", 80, LIGHT);
addEdge("Dharwad", "Challakere", 120, LIGHT);

addEdge("Dharwad", "Koppal", 85, LIGHT);
addEdge("Dharwad", "Mysore City Center", 280, LIGHT);

addEdge("Dharwad", "Shivamogga City Center", 150, LIGHT);
addEdge("Dharwad", "Bagalkot", 90, LIGHT);

addEdge("Dharwad", "Ranebennur", 50, LIGHT);
addEdge("Dharwad", "Hubballi Junction", 25, LIGHT);

addEdge("Dharwad", "Dharwad City Center", 15, LIGHT);
addEdge("Dharwad", "Hampi Bypass", 100, LIGHT);

addEdge("Dharwad", "Sadar Bazar", 25, LIGHT);
addEdge("Dharwad", "Hampi Ruins", 120, LIGHT);

addEdge("Dharwad", "Gokak City Center", 70, LIGHT);
addEdge("Dharwad", "Gokak Bypass", 90, LIGHT);

addEdge("Dharwad", "Kudligi", 130, LIGHT);
addEdge("Dharwad", "Mysore City Center", 280, LIGHT);

addEdge("Dharwad", "Talikoti", 140, LIGHT);
addEdge("Dharwad", "Raichur", 180, LIGHT);

addEdge("Dharwad", "Shivamogga", 170, LIGHT);
addEdge("Dharwad", "Haveri", 75, LIGHT);

addEdge("Dharwad", "Hampi", 120, LIGHT);
addEdge("Dharwad", "Bangalore City Center", 320, LIGHT);

addEdge("Dharwad", "Gadag Urban", 60, LIGHT);
addEdge("Dharwad", "Bagalkot Urban", 90, LIGHT);

addEdge("Pune", "Mumbai", 150, HEAVY);
addEdge("Pune", "Nashik", 180, MODERATE);

addEdge("Pune", "Satara", 110, LIGHT);
addEdge("Pune", "Solapur", 250, HEAVY);

addEdge("Pune", "Kolhapur", 220, LIGHT);
addEdge("Pune", "Aurangabad", 230, MODERATE);

addEdge("Pune", "Shirdi", 210, LIGHT);
addEdge("Pune", "Navi Mumbai", 160, HEAVY);

addEdge("Pune", "Kalyan", 140, LIGHT);
addEdge("Pune", "Thane", 120, HEAVY);

addEdge("Pune", "Alibaug", 200, MODERATE);
addEdge("Pune", "Lonavala", 65, LIGHT);

addEdge("Pune", "Mahabaleshwar", 120, LIGHT);
addEdge("Pune", "Matheran", 130, LIGHT);

addEdge("Pune", "Bhandardara", 170, MODERATE);
addEdge("Pune", "Karad", 180, LIGHT);

addEdge("Pune", "Pimpri-Chinchwad", 10, LIGHT);
addEdge("Pune", "Shivajinagar", 5, LIGHT);

addEdge("Pune", "Katraj", 15, LIGHT);
addEdge("Pune", "Hadapsar", 20, LIGHT);

addEdge("Pune", "Hinjewadi", 25, LIGHT);
addEdge("Pune", "Chinchwad", 10, LIGHT);

addEdge("Pune", "Dapodi", 12, LIGHT);
addEdge("Pune", "Shivane", 18, LIGHT);

addEdge("Pune", "Baner", 10, LIGHT);
addEdge("Pune", "Wakad", 15, LIGHT);

addEdge("Pune", "Viman Nagar", 20, LIGHT);
addEdge("Pune", "Aundh", 8, LIGHT);
addEdge("Pune", "Bavdhan", 18, LIGHT);

addEdge("Pune", "Kothrud", 7, LIGHT);
addEdge("Pune", "Deccan Gymkhana", 5, LIGHT);

addEdge("Pune", "Erandwane", 8, LIGHT);
addEdge("Pune", "Sadashiv Peth", 6, LIGHT);

addEdge("Pune", "Shivaji Nagar", 4, LIGHT);
addEdge("Pune", "Koregaon Park", 10, LIGHT);

addEdge("Pune", "Yerawada", 12, LIGHT);
addEdge("Pune", "Hadapsar", 20, LIGHT);

addEdge("Pune", "Viman Nagar", 25, LIGHT);
addEdge("Pune", "Wagholi", 35, LIGHT);

addEdge("Pune", "Dhanori", 40, LIGHT);
addEdge("Pune", "Bhosari", 18, LIGHT);

addEdge("Pune", "Nigdi", 25, LIGHT);
addEdge("Pune", "Bavdhan", 30, LIGHT);

addEdge("Pune", "Pashan", 18, LIGHT);
addEdge("Pune", "Shukrawar Peth", 10, LIGHT);

addEdge("Pune", "Camp", 5, LIGHT);
addEdge("Pune", "Deccan", 8, LIGHT);
addEdge("Pune", "Chandni Chowk", 15, LIGHT);

addEdge("Pune", "Kharadi", 22, LIGHT);
addEdge("Pune", "Vishrantwadi", 20, LIGHT);

addEdge("Pune", "Magarpatta", 15, LIGHT);
addEdge("Vijaypur", "Bagalkot", 40, LIGHT);

addEdge("Vijaypur", "Bijapur City Center", 10, LIGHT);
addEdge("Vijaypur", "Kudachi", 25, LIGHT);
addEdge("Vijaypur", "Solapur", 120, MODERATE);

addEdge("Vijaypur", "Bagalkot", 80, LIGHT);
addEdge("Vijaypur", "Koppal", 150, MODERATE);

addEdge("Vijaypur", "Gokak", 60, LIGHT);
addEdge("Vijaypur", "Bagewadi", 45, LIGHT);

addEdge("Vijaypur", "Raichur", 60, MODERATE);
addEdge("Vijaypur", "Chandrapur", 70, LIGHT);

addEdge("Vijaypur", "Haveri", 180, HEAVY);
addEdge("Vijaypur", "Dharwad", 180, LIGHT);

addEdge("Vijaypur", "Hassan", 160, MODERATE);
addEdge("Vijaypur", "Sangli", 140, MODERATE);

addEdge("Vijaypur", "Hutti", 70, LIGHT);
addEdge("Vijaypur", "Sadalga", 40, LIGHT);

addEdge("Vijaypur", "Lingasugur", 100, MODERATE);
addEdge("Vijaypur", "Chikodi", 90, LIGHT);

addEdge("Vijaypur", "Bhalki", 60, LIGHT);
addEdge("Vijaypur", "Borgaon", 45, LIGHT);

addEdge("Vijaypur", "Kittur", 120, MODERATE);
addEdge("Vijaypur", "Karnataka", 130, LIGHT);

addEdge("Vijaypur", "Tandur", 80, LIGHT);
addEdge("Vijaypur", "Bagalkot", 150, MODERATE);
addEdge("Vijaypur", "Jevargi", 110, LIGHT);

addEdge("Vijaypur", "Raichur City Center", 90, HEAVY);
addEdge("Vijaypur", "Devagiri", 130, LIGHT);

addEdge("Vijaypur", "Aurad", 60, LIGHT);
addEdge("Vijaypur", "Tandur", 120, HEAVY);

addEdge("Vijaypur", "Bidar", 90, LIGHT);
addEdge("Vijaypur", "Koppal", 150, LIGHT);

addEdge("Vijaypur", "Basavanabagewadi", 60, LIGHT);
addEdge("Vijaypur", "Hubballi", 160, MODERATE);

addEdge("Vijaypur", "Sukapur", 80, LIGHT);
addEdge("Vijaypur", "Mudalgi", 30, LIGHT);

addEdge("Vijaypur", "Hukkeri", 70, LIGHT);
addEdge("Vijaypur", "Alapur", 100, MODERATE);

addEdge("Vijaypur", "Ramanagiri", 85, LIGHT);
addEdge("Vijaypur", "Vidyapuri", 50, LIGHT);

addEdge("Vijaypur", "Shivapur", 80, LIGHT);
addEdge("Vijaypur", "Kadoli", 40, LIGHT);

addEdge("Vijaypur", "Arjunwadi", 30, LIGHT);
addEdge("Vijaypur", "Vasant Nagar", 50, LIGHT);
addEdge("Vijaypur", "Chandapura", 110, LIGHT);

addEdge("Vijaypur", "Ramnath", 70, LIGHT);
addEdge("Vijaypur", "Bellary", 130, MODERATE);

addEdge("Vijaypur", "Vijapur City Center", 30, LIGHT);
addEdge("Gadag", "Bagalkot", 80, LIGHT);

addEdge("Gadag", "Hubballi", 120, LIGHT);
addEdge("Gadag", "Bagalkot", 90, LIGHT);

addEdge("Gadag", "Raichur", 150, MODERATE);
addEdge("Gadag", "Mysore", 180, MODERATE);

addEdge("Gadag", "Bijapur", 70, LIGHT);
addEdge("Gadag", "Dharwad", 100, LIGHT);

addEdge("Gadag", "Vijaypur", 90, LIGHT);
addEdge("Gadag", "Bengaluru", 200, HEAVY);
addEdge("Gadag", "Chitradurga", 120, LIGHT);

addEdge("Gadag", "Shivamogga", 150, LIGHT);
addEdge("Gadag", "Hassan", 160, LIGHT);
addEdge("Gadag", "Tumkur", 130, LIGHT);

addEdge("Gadag", "Kalaburagi", 200, MODERATE);
addEdge("Gadag", "Karwar", 230, LIGHT);

addEdge("Gadag", "Udupi", 220, LIGHT);
addEdge("Gadag", "Koppal", 80, LIGHT);

addEdge("Gadag", "Mangalore", 240, MODERATE);
addEdge("Gadag", "Chikkamagaluru", 190, LIGHT);

addEdge("Gadag", "Solapur", 220, HEAVY);
addEdge("Gadag", "Lingsugur", 150, MODERATE);

addEdge("Gadag", "Yadgir", 110, LIGHT);
addEdge("Gadag", "Raichur City Center", 160, LIGHT);

addEdge("Gadag", "Ballari", 140, LIGHT);
addEdge("Gadag", "Hubballi", 90, LIGHT);

addEdge("Gadag", "Karnataka", 180, LIGHT);
addEdge("Gadag", "Bangalore", 190, MODERATE);

addEdge("Gadag", "Pune", 220, MODERATE);
addEdge("Gadag", "Bijapur City Center", 75, LIGHT);

addEdge("Gadag", "Sangli", 150, LIGHT);
addEdge("Gadag", "Gokak", 100, LIGHT);

addEdge("Gadag", "Basavana Bagewadi", 90, LIGHT);
addEdge("Gadag", "Koppal", 80, LIGHT);

addEdge("Gadag", "Raichur", 130, LIGHT);
addEdge("Gadag", "Bagalkot", 100, LIGHT);

addEdge("Gadag", "Mysuru", 180, LIGHT);
addEdge("Gadag", "Vijaypur", 160, LIGHT);

addEdge("Gadag", "Chandrapur", 100, LIGHT);
addEdge("Gadag", "Hukkeri", 70, LIGHT);

addEdge("Gadag", "Mudhol", 80, LIGHT);
addEdge("Gadag", "Bijapur", 60, LIGHT);

addEdge("Gadag", "Haveri", 130, LIGHT);
addEdge("Gadag", "Haveri", 100, LIGHT);

addEdge("Gadag", "Chandapura", 130, LIGHT);
addEdge("Gadag", "Lingasugur", 90, LIGHT);

addEdge("Gadag", "Manvi", 120, LIGHT);
addEdge("Gadag", "Shorapur", 140, LIGHT);

addEdge("Gadag", "Shahabad", 130, LIGHT);
addEdge("Gadag", "Gulbarga", 200, LIGHT);

addEdge("Gadag", "Athani", 70, LIGHT);
addEdge("Tumkur", "Bengaluru", 70, LIGHT);
addEdge("Tumkur", "Mysore", 150, MODERATE);

addEdge("Tumkur", "Hassan", 110, LIGHT);
addEdge("Tumkur", "Chitradurga", 80, LIGHT);

addEdge("Tumkur", "Shimoga", 170, LIGHT);

addEdge("Tumkur", "Bellary", 150, MODERATE);
addEdge("Tumkur", "Hubballi", 220, HEAVY);

addEdge("Tumkur", "Bagalkot", 130, LIGHT);
addEdge("Tumkur", "Davangere", 90, LIGHT);

addEdge("Tumkur", "Vijaypur", 160, LIGHT);
addEdge("Tumkur", "Gulbarga", 200, LIGHT);

addEdge("Tumkur", "Raichur", 180, MODERATE);
addEdge("Tumkur", "Haveri", 130, LIGHT);

addEdge("Tumkur", "Yadgir", 170, LIGHT);
addEdge("Tumkur", "Mandya", 40, LIGHT);

addEdge("Tumkur", "Udupi", 200, LIGHT);
addEdge("Tumkur", "Dharwad", 220, LIGHT);

addEdge("Tumkur", "Bijapur", 150, LIGHT);
addEdge("Tumkur", "Koppal", 120, LIGHT);

addEdge("Tumkur", "Karwar", 210, LIGHT);
addEdge("Tumkur", "Mangaluru", 220, MODERATE);

addEdge("Tumkur", "Chikkamagaluru", 140, LIGHT);
addEdge("Tumkur", "Solapur", 250, HEAVY);

addEdge("Tumkur", "Bagalkot", 130, LIGHT);
addEdge("Tumkur", "Raichur City Center", 170, LIGHT);
addEdge("Tumkur", "Mysuru", 140, LIGHT);

addEdge("Tumkur", "Vijaypur", 160, LIGHT);
addEdge("Tumkur", "Bengaluru", 70, LIGHT);

addEdge("Tumkur", "Hassan", 110, LIGHT);
addEdge("Tumkur", "Shivamogga", 180, MODERATE);

addEdge("Tumkur", "Chikmagalur", 130, LIGHT);
addEdge("Tumkur", "Kalaburagi", 200, LIGHT);

addEdge("Tumkur", "Raichur", 180, MODERATE);
addEdge("Tumkur", "Chitradurga", 100, LIGHT);

addEdge("Tumkur", "Bailhongal", 160, LIGHT);
addEdge("Tumkur", "Koppal", 120, LIGHT);

addEdge("Tumkur", "Sira", 70, LIGHT);
addEdge("Tumkur", "Arsikere", 90, LIGHT);

addEdge("Tumkur", "Channarayapatna", 85, LIGHT);
addEdge("Tumkur", "Nagamangala", 60, LIGHT);

addEdge("Tumkur", "Madhugiri", 60, LIGHT);
addEdge("Tumkur", "Pavagada", 100, LIGHT);

addEdge("Tumkur", "Koratagere", 50, LIGHT);
addEdge("Tumkur", "Kunigal", 55, LIGHT);

addEdge("Tumkur", "Tiptur", 70, LIGHT);
addEdge("Tumkur", "Bangalore Rural", 80, LIGHT);

addEdge("Tumkur", "Srinivaspura", 120, LIGHT);
addEdge("Tumkur", "Hoskote", 110, LIGHT);

addEdge("Tumkur", "Magadi", 70, LIGHT);
addEdge("Tumkur", "Doddaballapura", 100, LIGHT);

addEdge("Tumkur", "Challakere", 130, LIGHT);
addEdge("Tumkur", "Yelahanka", 100, LIGHT);

addEdge("Tumkur", "Vijayanagar", 140, LIGHT);
addEdge("Tumkur", "Hebbal", 100, LIGHT);
addEdge("Tumkur", "Koramangala", 130, LIGHT);

addEdge("Tumkur", "Indiranagar", 150, LIGHT);
addEdge("Tumkur", "Whitefield", 160, LIGHT);

addEdge("Tumkur", "Bangalore South", 80, LIGHT);
addEdge("Tumkur", "Basavanagudi", 120, LIGHT);
addEdge("Tumkur", "Ulsoor", 130, LIGHT);

addEdge("Tumkur", "Shivaji Nagar", 140, LIGHT);
addEdge("Tumkur", "Banashankari", 130, LIGHT);

addEdge("Shivamogga", "Bengaluru", 280, HEAVY);
addEdge("Shivamogga", "Mysore", 150, MODERATE);

addEdge("Shivamogga", "Hubballi", 180, HEAVY);
addEdge("Shivamogga", "Hassan", 170, MODERATE);

addEdge("Shivamogga", "Chitradurga", 120, LIGHT);
addEdge("Shivamogga", "Raichur", 220, LIGHT);

addEdge("Shivamogga", "Bagalkot", 200, LIGHT);
addEdge("Shivamogga", "Mandya", 160, LIGHT);
addEdge("Shivamogga", "Davangere", 130, LIGHT);

addEdge("Shivamogga", "Tumkur", 170, LIGHT);
addEdge("Shivamogga", "Vijaypur", 230, LIGHT);

addEdge("Shivamogga", "Gulbarga", 250, HEAVY);
addEdge("Shivamogga", "Chikkamagaluru", 100, LIGHT);

addEdge("Shivamogga", "Haveri", 150, LIGHT);
addEdge("Shivamogga", "Udupi", 200, LIGHT);

addEdge("Shivamogga", "Belagavi", 220, LIGHT);
addEdge("Shivamogga", "Dharwad", 230, HEAVY);

addEdge("Shivamogga", "Raichur City Center", 230, LIGHT);
addEdge("Shivamogga", "Bangalore", 280, HEAVY);

addEdge("Shivamogga", "Koppal", 150, LIGHT);
addEdge("Shivamogga", "Kalaburagi", 270, LIGHT);

addEdge("Shivamogga", "Karwar", 300, LIGHT);

addEdge("Shivamogga", "Mangaluru", 280, MODERATE);
addEdge("Shivamogga", "Bagalkot", 200, LIGHT);

addEdge("Shivamogga", "Hoskote", 220, LIGHT);
addEdge("Shivamogga", "Shimoga City Center", 10, LIGHT);

addEdge("Shivamogga", "Sagara", 40, LIGHT);
addEdge("Shivamogga", "Tirthahalli", 50, LIGHT);

addEdge("Shivamogga", "Siddapura", 60, LIGHT);
addEdge("Shivamogga", "Shikaripura", 70, LIGHT);

addEdge("Shivamogga", "Bhadravati", 80, LIGHT);
addEdge("Shivamogga", "Jog Falls", 100, LIGHT);

addEdge("Shivamogga", "Kudligi", 120, LIGHT);
addEdge("Shivamogga", "Shivapura", 130, LIGHT);

addEdge("Shivamogga", "Bhadravati", 80, LIGHT);
addEdge("Shivamogga", "Tarikere", 120, LIGHT);

addEdge("Shivamogga", "Balehonnur", 90, LIGHT);
addEdge("Shivamogga", "Thirthahalli", 70, LIGHT);

addEdge("Shivamogga", "Shivamogga", 0, LIGHT);
addEdge("Shivamogga", "Kodagu", 130, LIGHT);

addEdge("Shivamogga", "Vijayanagar", 180, LIGHT);
addEdge("Shivamogga", "Raichur", 220, LIGHT);

addEdge("Shivamogga", "Mysore", 150, MODERATE);


addEdge("Ballari", "Hubballi", 170, HEAVY);
addEdge("Ballari", "Belagavi", 180, MODERATE);

addEdge("Ballari", "Raichur", 130, LIGHT);

addEdge("Ballari", "Chitradurga", 150, LIGHT);

addEdge("Ballari", "Bagalkot", 200, LIGHT);
addEdge("Ballari", "Davangere", 160, LIGHT);
addEdge("Ballari", "Vijaypur", 170, LIGHT);

addEdge("Ballari", "Mysore", 210, HEAVY);
addEdge("Ballari", "Mandya", 180, LIGHT);

addEdge("Ballari", "Gulbarga", 240, HEAVY);
addEdge("Ballari", "Tumkur", 180, LIGHT);

addEdge("Ballari", "Hassan", 210, MODERATE);
addEdge("Ballari", "Shimoga", 200, LIGHT);

addEdge("Ballari", "Bengaluru", 230, HEAVY);
addEdge("Ballari", "Haveri", 140, LIGHT);
addEdge("Ballari", "Udupi", 250, LIGHT);

addEdge("Ballari", "Chikkamagaluru", 230, LIGHT);
addEdge("Ballari", "Shivamogga", 180, LIGHT);

addEdge("Ballari", "Karwar", 300, LIGHT);
addEdge("Ballari", "Mangaluru", 260, LIGHT);

addEdge("Ballari", "Raichur City Center", 120, LIGHT);
addEdge("Ballari", "Kalaburagi", 220, LIGHT);

addEdge("Ballari", "Pune", 370, LIGHT);
addEdge("Ballari", "Bagalkot", 200, LIGHT);
addEdge("Ballari", "Yadgir", 90, LIGHT);

addEdge("Ballari", "Hospet", 35, LIGHT);
addEdge("Ballari", "Sindhanur", 75, LIGHT);

addEdge("Ballari", "Srinivaspur", 200, LIGHT);
addEdge("Ballari", "Adoni", 110, LIGHT);

addEdge("Ballari", "Raichur City", 120, LIGHT);
addEdge("Ballari", "Bangalore", 220, HEAVY);

addEdge("Ballari", "Koppal", 60, LIGHT);
addEdge("Ballari", "Hoskote", 230, LIGHT);

addEdge("Ballari", "Kolar", 210, LIGHT);
addEdge("Ballari", "Bhadravati", 180, LIGHT);

addEdge("Ballari", "Challakere", 90, LIGHT);
addEdge("Ballari", "Sandur", 20, LIGHT);
addEdge("Ballari", "Dharwad", 220, LIGHT);

addEdge("Ballari", "Belur", 230, LIGHT);
addEdge("Ballari", "Madhugiri", 220, LIGHT);

addEdge("Ballari", "Devaragudda", 120, LIGHT);
addEdge("Ballari", "Bagepalli", 210, LIGHT);

addEdge("Ballari", "Tandur", 190, LIGHT);
addEdge("Ballari", "Chintamani", 200, LIGHT);

addEdge("Ballari", "Yelandur", 220, LIGHT);
addEdge("Ballari", "Kolar", 210, LIGHT);

addEdge("Ballari", "Hassan", 210, MODERATE);
addEdge("Ballari", "Chikballapur", 230, LIGHT);

addEdge("Chikkamagaluru", "Mudigere", 35, LIGHT);
addEdge("Chikkamagaluru", "Kadur", 40, LIGHT);

addEdge("Chikkamagaluru", "Sringeri", 50, MODERATE);
addEdge("Chikkamagaluru", "Aldur", 25, LIGHT);

addEdge("Chikkamagaluru", "Birur", 20, LIGHT);
addEdge("Chikkamagaluru", "Tarikere", 15, LIGHT);

addEdge("Chikkamagaluru", "Shimoga", 80, MODERATE);
addEdge("Chikkamagaluru", "Mudigere", 35, LIGHT);

addEdge("Chikkamagaluru", "Belur", 40, MODERATE);
addEdge("Chikkamagaluru", "Hassan", 60, HEAVY);

addEdge("Chikkamagaluru", "Bengaluru", 240, HEAVY);
addEdge("Chikkamagaluru", "Mysuru", 150, MODERATE);

addEdge("Chikkamagaluru", "Mangaluru", 140, LIGHT);
addEdge("Chikkamagaluru", "Agumbe", 25, LIGHT);

addEdge("Chikkamagaluru", "Thirthahalli", 30, LIGHT);
addEdge("Chikkamagaluru", "Tarikere", 15, LIGHT);

addEdge("Chikkamagaluru", "Sringeri", 50, MODERATE);
addEdge("Chikkamagaluru", "Aldur", 25, LIGHT);

addEdge("Chikkamagaluru", "Kalasa", 30, LIGHT);
addEdge("Chikkamagaluru", "Kudremukh", 20, MODERATE);

addEdge("Chikkamagaluru", "Karkala", 40, LIGHT);

addEdge("Chikkamagaluru", "Malkhed", 35, LIGHT);
addEdge("Chikkamagaluru", "Kalgi", 30, LIGHT);

addEdge("Chikkamagaluru", "Horanadu", 35, LIGHT);
addEdge("Chikkamagaluru", "Vijayapura", 50, LIGHT);

addEdge("Chikkamagaluru", "Bagalkot", 200, LIGHT);
addEdge("Chikkamagaluru", "Chitradurga", 120, LIGHT);

addEdge("Chikkamagaluru", "Raichur", 240, HEAVY);
addEdge("Chikkamagaluru", "Mandya", 150, LIGHT);

addEdge("Chikkamagaluru", "Gulbarga", 220, HEAVY);
addEdge("Chikkamagaluru", "Belagavi", 240, LIGHT);

addEdge("Chikkamagaluru", "Kolar", 230, LIGHT);
addEdge("Chikkamagaluru", "Yelandur", 150, LIGHT);

addEdge("Chikkamagaluru", "Bagalkot", 180, LIGHT);
addEdge("Chikkamagaluru", "Tandur", 200, LIGHT);

addEdge("Chikkamagaluru", "Bagalkot", 170, LIGHT);
addEdge("Chikkamagaluru", "Srinivaspur", 180, LIGHT);

addEdge("Chikkamagaluru", "Hassan", 200, MODERATE);
addEdge("Chikkamagaluru", "Vijaypur", 170, LIGHT);

addEdge("Chikkamagaluru", "Yadgir", 230, LIGHT);
addEdge("Chikkamagaluru", "Raichur City Center", 240, HEAVY);

addEdge("Chikkamagaluru", "Hospet", 230, LIGHT);
addEdge("Chikkamagaluru", "Bangalore", 240, HEAVY);

addEdge("Chikkamagaluru", "Vijayapura", 160, LIGHT);
addEdge("Chikkamagaluru", "Challakere", 180, LIGHT);

addEdge("Chikkamagaluru", "Yadgir", 230, LIGHT);
addEdge("Chikkamagaluru", "Srinivaspur", 210, LIGHT);

addEdge("Chikkamagaluru", "Bagalkot", 170, LIGHT);
addEdge("Chikkamagaluru", "Hospet", 230, LIGHT);

addEdge("Chikkamagaluru", "Mandya", 140, LIGHT);
addEdge("Udupi", "Kundapura", 40, LIGHT);

addEdge("Udupi", "Manipal", 5, LIGHT);
addEdge("Udupi", "Karkala", 25, LIGHT);

addEdge("Udupi", "Bantwal", 60, MODERATE);
addEdge("Udupi", "Puttur", 80, HEAVY);

addEdge("Udupi", "Mangalore", 60, MODERATE);
addEdge("Udupi", "Murudeshwar", 50, LIGHT);

addEdge("Udupi", "Byndoor", 40, LIGHT);
addEdge("Udupi", "Kundapura", 35, LIGHT);

addEdge("Udupi", "Karkala", 20, LIGHT);
addEdge("Udupi", "Bajpe", 30, LIGHT);

addEdge("Udupi", "Karkala", 25, LIGHT);
addEdge("Udupi", "Kundapura", 40, MODERATE);

addEdge("Udupi", "Manipal", 5, LIGHT);
addEdge("Udupi", "Bantwal", 60, LIGHT);

addEdge("Udupi", "Sullia", 90, HEAVY);
addEdge("Udupi", "Puttur", 85, MODERATE);

addEdge("Udupi", "Mangalore", 60, LIGHT);
addEdge("Udupi", "Mudigere", 120, LIGHT);

addEdge("Udupi", "Belthangady", 75, LIGHT);
addEdge("Udupi", "Sakleshpur", 140, MODERATE);

addEdge("Udupi", "Kodagu", 180, HEAVY);
addEdge("Udupi", "Chikmagalur", 140, LIGHT);

addEdge("Udupi", "Mysore", 210, HEAVY);
addEdge("Udupi", "Bangalore", 350, HEAVY);

addEdge("Udupi", "Coorg", 180, LIGHT);
addEdge("Udupi", "Shimoga", 160, MODERATE);

addEdge("Udupi", "Hassan", 160, LIGHT);
addEdge("Udupi", "Kodagu", 150, HEAVY);

addEdge("Udupi", "Honavar", 60, LIGHT);
addEdge("Udupi", "Karwar", 100, MODERATE);

addEdge("Udupi", "Mangalore", 60, LIGHT);
addEdge("Udupi", "Baindur", 50, LIGHT);

addEdge("Udupi", "Hampi", 130, HEAVY);
addEdge("Udupi", "Bijapur", 200, MODERATE);

addEdge("Udupi", "Raichur", 240, HEAVY);
addEdge("Udupi", "Hospet", 140, LIGHT);

addEdge("Udupi", "Koppal", 180, LIGHT);

addEdge("Udupi", "Bagalkot", 220, HEAVY);
addEdge("Udupi", "Chitradurga", 180, LIGHT);

addEdge("Udupi", "Mysore", 200, HEAVY);
addEdge("Udupi", "Vijayapura", 230, LIGHT);

addEdge("Udupi", "Tumkur", 230, HEAVY);
addEdge("Udupi", "Kolar", 270, HEAVY);

addEdge("Udupi", "Belagavi", 320, HEAVY);
addEdge("Udupi", "Hubballi", 330, LIGHT);

addEdge("Udupi", "Shivamogga", 220, MODERATE);
addEdge("Udupi", "Sullia", 90, LIGHT);
addEdge("Udupi", "Hassan", 140, LIGHT);

addEdge("Bidar City Center", "Basavakalyan", 70, MODERATE);
addEdge("Bidar City Center", "Bhalki", 50, LIGHT);

addEdge("Bidar City Center", "Aurad", 60, LIGHT);
addEdge("Bidar City Center", "Humnabad", 80, MODERATE);

addEdge("Bidar City Center", "Chitgoppa", 45, LIGHT);
addEdge("Bidar City Center", "Kamthana", 15, LIGHT);
addEdge("Bidar City Center", "Naubad", 10, LIGHT);

addEdge("Bidar City Center", "Manhalli", 20, LIGHT);
addEdge("Bidar City Center", "Janawada", 25, LIGHT);

addEdge("Bidar City Center", "Chikpet", 8, LIGHT);
addEdge("Bidar City Center", "Gumpa", 12, LIGHT);

addEdge("Bidar City Center", "Mangalpet", 18, MODERATE);
addEdge("Bidar City Center", "Siddeshwar Colony", 14, LIGHT);

addEdge("Bidar City Center", "Baridabad", 17, LIGHT);
addEdge("Bidar City Center", "Aliabad", 22, LIGHT);

addEdge("Bidar City Center", "Udgir", 65, LIGHT);
addEdge("Bidar City Center", "Zahirabad", 50, LIGHT);

addEdge("Bidar City Center", "Aurangabad", 180, HEAVY);
addEdge("Bidar City Center", "Kalaburagi", 120, HEAVY);

addEdge("Bidar City Center", "Shahabad", 95, MODERATE);
addEdge("Bidar City Center", "Sedam", 105, LIGHT);

addEdge("Bidar City Center", "Tandur", 130, MODERATE);
addEdge("Bidar City Center", "Vikarabad", 140, HEAVY);

addEdge("Bidar City Center", "Hyderabad", 120, MODERATE);
addEdge("Bidar City Center", "Basavakalyan", 70, LIGHT);

addEdge("Bidar City Center", "Bhalki", 50, MODERATE);
addEdge("Bidar City Center", "Aurad", 65, LIGHT);

addEdge("Bidar City Center", "Chincholi", 90, MODERATE);
addEdge("Bidar City Center", "Humnabad", 75, LIGHT);

addEdge("Bidar City Center", "Raichur", 200, HEAVY);
addEdge("Bidar City Center", "Bijapur", 210, HEAVY);

addEdge("Bidar City Center", "Solapur", 170, MODERATE);
addEdge("Bidar City Center", "Pune", 300, HEAVY);

addEdge("Bidar City Center", "Nanded", 110, LIGHT);
addEdge("Bidar City Center", "Latur", 150, MODERATE);

addEdge("Bidar City Center", "Osmanabad", 140, HEAVY);
addEdge("Bidar City Center", "Zaheerabad", 55, LIGHT);

addEdge("Bidar City Center", "Mantralayam", 180, MODERATE);
addEdge("Bidar City Center", "Karimnagar", 160, MODERATE);

addEdge("Bidar City Center", "Warangal", 240, HEAVY);
addEdge("Bidar City Center", "Nizamabad", 140, MODERATE);

addEdge("Bidar City Center", "Kamareddy", 120, LIGHT);
addEdge("Bidar City Center", "Adilabad", 210, MODERATE);

addEdge("Bidar City Center", "Parbhani", 150, LIGHT);
addEdge("Bidar City Center", "Jalna", 200, HEAVY);

addEdge("Bidar City Center", "Nagpur", 400, HEAVY);
addEdge("Bidar City Center", "Aurangabad", 180, MODERATE);

addEdge("Bidar City Center", "Gulbarga", 130, MODERATE);
addEdge("Bidar City Center", "Bangalore", 650, HEAVY);

addEdge("Bangalore", "Mysore", 150, MODERATE);
addEdge("Bangalore", "Tumkur", 70, LIGHT);

addEdge("Bangalore", "Hassan", 185, MODERATE);
addEdge("Bangalore", "Belagavi", 505, HEAVY);

addEdge("Bangalore", "Hubballi", 410, HEAVY);
addEdge("Bangalore", "Dharwad", 430, HEAVY);

addEdge("Bangalore", "Shimoga", 280, MODERATE);
addEdge("Bangalore", "Udupi", 350, LIGHT);

addEdge("Bangalore", "Raichur", 480, MODERATE);
addEdge("Bangalore", "Mandya", 100, LIGHT);

addEdge("Bangalore", "Bagalkot", 580, HEAVY);
addEdge("Bangalore", "Vijaypur", 610, HEAVY);

addEdge("Bangalore", "Bidar", 710, HEAVY);
addEdge("Bangalore", "Pune", 850, HEAVY);


addEdge("Mysore", "Hassan", 115, LIGHT);
addEdge("Mysore", "Tumkur", 145, LIGHT);

addEdge("Mysore", "Mandya", 45, LIGHT);
addEdge("Mysore", "Shimoga", 200, MODERATE);

addEdge("Mysore", "Belagavi", 495, HEAVY);
addEdge("Mysore", "Hubballi", 390, HEAVY);

addEdge("Mysore", "Udupi", 330, MODERATE);
addEdge("Mysore", "Raichur", 500, HEAVY);

addEdge("Mysore", "Vijaypur", 620, HEAVY);
addEdge("Mysore", "Bidar", 750, HEAVY);


addEdge("Tumkur", "Hassan", 130, LIGHT);

addEdge("Tumkur", "Shimoga", 140, LIGHT);
addEdge("Tumkur", "Raichur", 350, MODERATE);
addEdge("Tumkur", "Udupi", 270, LIGHT);

addEdge("Tumkur", "Mandya", 90, LIGHT);
addEdge("Tumkur", "Bagalkot", 510, HEAVY);

addEdge("Tumkur", "Vijaypur", 540, HEAVY);


addEdge("Hassan", "Shimoga", 90, LIGHT);
addEdge("Hassan", "Mandya", 65, LIGHT);

addEdge("Hassan", "Belagavi", 355, MODERATE);
addEdge("Hassan", "Hubballi", 270, MODERATE);

addEdge("Hassan", "Dharwad", 290, MODERATE);
addEdge("Hassan", "Udupi", 170, LIGHT);


addEdge("Belagavi", "Hubballi", 90, LIGHT);

addEdge("Belagavi", "Dharwad", 70, LIGHT);
addEdge("Belagavi", "Bagalkot", 140, MODERATE);

addEdge("Belagavi", "Vijaypur", 150, MODERATE);
addEdge("Belagavi", "Raichur", 310, MODERATE);

addEdge("Belagavi", "Pune", 90, LIGHT);

addEdge("Hubballi", "Dharwad", 20, LIGHT);

addEdge("Hubballi", "Bagalkot", 130, LIGHT);
addEdge("Hubballi", "Vijaypur", 200, MODERATE);

addEdge("Hubballi", "Shimoga", 190, LIGHT);


addEdge("Dharwad", "Bagalkot", 150, LIGHT);
addEdge("Dharwad", "Vijaypur", 210, MODERATE);


addEdge("Raichur", "Bagalkot", 160, LIGHT);

addEdge("Raichur", "Vijaypur", 170, MODERATE);
addEdge("Raichur", "Bidar", 200, HEAVY);


addEdge("Bidar", "Vijaypur", 230, MODERATE);
addEdge("Bidar", "Pune", 400, HEAVY);


addEdge("Pune", "Bagalkot", 300, MODERATE);
addEdge("Pune", "Hubballi", 420, MODERATE);

addEdge("Pune", "Vijaypur", 280, LIGHT);


addEdge("Shimoga", "Udupi", 110, LIGHT);
addEdge("Shimoga", "Mandya", 200, LIGHT);


addEdge("Mandya", "Bagalkot", 500, HEAVY);

addEdge("Mandya", "Vijaypur", 600, HEAVY);

addEdge("Mandya", "Bidar", 700, HEAVY);
addEdge("Kolar City Center", "Andersonpet", 6, LIGHT);

addEdge("Kolar City Center", "Bethamangala", 15, MODERATE);
addEdge("Kolar City Center", "Malur", 25, LIGHT);

addEdge("Kolar City Center", "Bangarapet", 18, LIGHT);
addEdge("Kolar City Center", "Mulbagal", 30, MODERATE);

addEdge("Kolar City Center", "Kurubarapet", 5, LIGHT);
addEdge("Kolar City Center", "Jangamakote", 12, LIGHT);

addEdge("Kolar City Center", "Srinivaspur", 22, MODERATE);
addEdge("Kolar City Center", "Dommasandra", 35, LIGHT);

addEdge("Kolar City Center", "Vemagal", 14, LIGHT);


addEdge("Andersonpet", "Bethamangala", 10, LIGHT);
addEdge("Andersonpet", "Bangarapet", 12, LIGHT);

addEdge("Andersonpet", "Mulbagal", 35, MODERATE);
addEdge("Andersonpet", "Srinivaspur", 20, MODERATE);

addEdge("Andersonpet", "Dommasandra", 40, LIGHT);


addEdge("Bethamangala", "Malur", 28, MODERATE);
addEdge("Bethamangala", "Bangarapet", 12, LIGHT);

addEdge("Bethamangala", "Kurubarapet", 8, LIGHT);
addEdge("Bethamangala", "Jangamakote", 25, MODERATE);


addEdge("Malur", "Dommasandra", 20, LIGHT);

addEdge("Malur", "Vemagal", 10, LIGHT);
addEdge("Malur", "Mulbagal", 38, MODERATE);

addEdge("Malur", "Srinivaspur", 30, MODERATE);


addEdge("Bangarapet", "Mulbagal", 18, LIGHT);
addEdge("Bangarapet", "Kurubarapet", 6, LIGHT);

addEdge("Bangarapet", "Vemagal", 12, LIGHT);
addEdge("Bangarapet", "Dommasandra", 28, MODERATE);

addEdge("Mulbagal", "Srinivaspur", 25, MODERATE);
addEdge("Mulbagal", "Jangamakote", 30, MODERATE);

addEdge("Kurubarapet", "Vemagal", 9, LIGHT);

addEdge("Kurubarapet", "Dommasandra", 15, LIGHT);
addEdge("Kurubarapet", "Srinivaspur", 18, MODERATE);

addEdge("Karwar City Center", "Sadashivgad", 6, LIGHT);
addEdge("Karwar City Center", "Kadwad", 8, LIGHT);

addEdge("Karwar City Center", "Majali", 12, MODERATE);
addEdge("Karwar City Center", "Kumta", 25, MODERATE);

addEdge("Karwar City Center", "Ankola", 35, LIGHT);
addEdge("Karwar City Center", "Devbagh", 5, LIGHT);

addEdge("Karwar City Center", "Kodibag", 4, LIGHT);
addEdge("Karwar City Center", "Guddalli", 10, LIGHT);

addEdge("Karwar City Center", "Chendia", 18, MODERATE);
addEdge("Karwar City Center", "Binaga", 7, LIGHT);



addEdge("Sadashivgad", "Kadwad", 6, LIGHT);
addEdge("Sadashivgad", "Majali", 10, LIGHT);

addEdge("Sadashivgad", "Devbagh", 8, LIGHT);
addEdge("Sadashivgad", "Kumta", 28, MODERATE);


addEdge("Kadwad", "Majali", 8, LIGHT);
addEdge("Kadwad", "Guddalli", 12, MODERATE);

addEdge("Kadwad", "Chendia", 10, MODERATE);


addEdge("Majali", "Ankola", 40, MODERATE);
addEdge("Majali", "Binaga", 5, LIGHT);

addEdge("Majali", "Kumta", 30, MODERATE);

addEdge("Devbagh", "Kodibag", 5, LIGHT);

addEdge("Devbagh", "Guddalli", 8, LIGHT);
addEdge("Devbagh", "Chendia", 15, MODERATE);


addEdge("Kodibag", "Binaga", 4, LIGHT);
addEdge("Kodibag", "Chendia", 9, LIGHT);

addEdge("Kodibag", "Guddalli", 6, LIGHT);
addEdge("Kodagu City Center", "Madikeri", 10, LIGHT);

addEdge("Kodagu City Center", "Kushalnagar", 15, MODERATE);
addEdge("Kodagu City Center", "Virajpet", 20, MODERATE);

addEdge("Kodagu City Center", "Gonikoppal", 25, LIGHT);
addEdge("Kodagu City Center", "Somwarpet", 18, LIGHT);

addEdge("Kodagu City Center", "Pollibetta", 22, LIGHT);
addEdge("Kodagu City Center", "Suntikoppa", 12, LIGHT);

addEdge("Kodagu City Center", "Cherambane", 16, LIGHT);
addEdge("Kodagu City Center", "Napoklu", 14, LIGHT);

addEdge("Kodagu City Center", "Bhagamandala", 19, MODERATE);

addEdge("Madikeri", "Kushalnagar", 20, LIGHT);

addEdge("Madikeri", "Virajpet", 22, MODERATE);
addEdge("Madikeri", "Suntikoppa", 12, LIGHT);

addEdge("Madikeri", "Cherambane", 8, LIGHT);
addEdge("Madikeri", "Bhagamandala", 15, MODERATE);

addEdge("Kushalnagar", "Suntikoppa", 10, LIGHT);

addEdge("Kushalnagar", "Somwarpet", 18, MODERATE);
addEdge("Kushalnagar", "Gonikoppal", 25, LIGHT);

addEdge("Virajpet", "Gonikoppal", 12, LIGHT);

addEdge("Virajpet", "Pollibetta", 10, LIGHT);
addEdge("Virajpet", "Napoklu", 15, LIGHT);

addEdge("Gonikoppal", "Pollibetta", 8, LIGHT);
addEdge("Gonikoppal", "Ponnampet", 10, LIGHT);

addEdge("Gonikoppal", "Srimangala", 18, MODERATE);

addEdge("Pollibetta", "Ponnampet", 6, LIGHT);
addEdge("Pollibetta", "Napoklu", 20, MODERATE);

addEdge("Somwarpet", "Suntikoppa", 14, LIGHT);
addEdge("Somwarpet", "Madapura", 10, LIGHT);
addEdge("Somwarpet", "Shanivarsanthe", 12, LIGHT);

addEdge("Suntikoppa", "Cherambane", 10, LIGHT);
addEdge("Suntikoppa", "Napoklu", 18, LIGHT);

addEdge("Cherambane", "Bhagamandala", 12, LIGHT);

addEdge("Napoklu", "Bhagamandala", 10, LIGHT);
addEdge("Napoklu", "Srimangala", 22, MODERATE);

addEdge("Bhagamandala", "Talacauvery", 8, LIGHT);

addEdge("Ponnampet", "Srimangala", 15, LIGHT);
addEdge("Ponnampet", "Thithimathi", 18, MODERATE);

addEdge("Srimangala", "Thithimathi", 10, LIGHT);
addEdge("Srimangala", "Irupu Falls", 12, MODERATE);

addEdge("Thithimathi", "Nagarhole", 20, LIGHT);
addEdge("Thithimathi", "Kutta", 15, LIGHT);

addEdge("Kutta", "Nagarhole", 12, LIGHT);
addEdge("Kutta", "Gonikoppal", 22, LIGHT);

addEdge("Talacauvery", "Madikeri", 20, MODERATE);
addEdge("Talacauvery", "Bhagamandala", 8, LIGHT);

addEdge("Shanivarsanthe", "Somwarpet", 12, LIGHT);
addEdge("Shanivarsanthe", "Madapura", 15, LIGHT);

addEdge("Madapura", "Somwarpet", 10, LIGHT);
addEdge("Madapura", "Shanivarsanthe", 15, LIGHT);

// Hyderabad City Areas connections
addEdge("Hyderabad", "Hyderabad City Center", 0, LIGHT);

addEdge("Hyderabad City Center", "Banjara Hills", 5, LIGHT);
addEdge("Hyderabad City Center", "Hitech City", 10, MODERATE);

addEdge("Hyderabad City Center", "Ameerpet", 4, LIGHT);
addEdge("Hyderabad City Center", "Kukatpally", 8, MODERATE);

addEdge("Hyderabad City Center", "Gachibowli", 12, HEAVY);
addEdge("Hyderabad City Center", "Secunderabad", 15, HEAVY);

addEdge("Hyderabad City Center", "Madhapur", 9, MODERATE);
addEdge("Hyderabad City Center", "Jubilee Hills", 6, LIGHT);

addEdge("Hyderabad City Center", "Old City", 18, HEAVY);


addEdge("Banjara Hills", "Road No 12", 4, LIGHT);

addEdge("Banjara Hills", "Road No 1", 3, LIGHT);

addEdge("Banjara Hills", "Panjagutta", 5, LIGHT);
addEdge("Banjara Hills", "Somajiguda", 4, LIGHT);


addEdge("Hitech City", "Madhapur", 7, LIGHT);

addEdge("Hitech City", "Kondapur", 8, MODERATE);

addEdge("Hitech City", "Gachibowli", 5, LIGHT);

addEdge("Hitech City", "Kukatpally", 9, MODERATE);


addEdge("Ameerpet", "S R Nagar", 3, LIGHT);
addEdge("Ameerpet", "Madhura Nagar", 4, LIGHT);

addEdge("Ameerpet", "Yellareddyguda", 2, LIGHT);

addEdge("Ameerpet", "Barkatpura", 6, MODERATE);


addEdge("Kukatpally", "KPHB", 6, MODERATE);
addEdge("Kukatpally", "JNTU", 8, MODERATE);

addEdge("Kukatpally", "Bachupally", 10, LIGHT);


addEdge("Gachibowli", "Financial District", 3, LIGHT);

    }

    void addEdge(const string& source, const string& destination, int distance, TrafficCondition traffic)

    {
        adjList[source].emplace_back(destination, make_pair(distance, traffic));

        adjList[destination].emplace_back(source, make_pair(distance, traffic));
    }

    void printGraph() const

     {
        for (const auto& node : adjList)

            {
            cout << node.first << " -> ";
            for (const auto& neighbor : node.second)

            {
                cout << "(" << neighbor.first << ", Distance: " << neighbor.second.first
                     << ", Traffic: " << neighbor.second.second << ") ";
            }
            cout << endl;


        }


    }

    void findOptimalRoute(const string& start, const string& end) const


    {
        if (adjList.find(start) == adjList.end() || adjList.find(end) == adjList.end())


            {


            cout << "Error: One or both locations are not in the network.\n";
            return;

        }

        unordered_map<string, int> distances;
        unordered_map<string, string> previous;

        auto compare = [](pair<int, string> a, pair<int, string> b)

        {
             return a.first > b.first; };


        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(compare)> pq(compare);

        for (const auto& node : adjList)

            {

            distances[node.first] = INT_MAX;

            }

        distances[start] = 0;

        pq.push({0, start});

        while (!pq.empty())

            {

            auto [currentDistance, currentNode] = pq.top();
            pq.pop();

            if (currentDistance > distances[currentNode]) continue;

            for (const auto& neighbor : adjList.at(currentNode))

                {

                int trafficMultiplier = 1;
                if (neighbor.second.second == HEAVY)

                {
                    trafficMultiplier = 2;

                }

            else if (neighbor.second.second == MODERATE)

                 {

                    trafficMultiplier = 1.5;

                 }

                int newDistance = currentDistance + neighbor.second.first * trafficMultiplier;

                if (newDistance < distances[neighbor.first])

                    {

                    distances[neighbor.first] = newDistance;
                    previous[neighbor.first] = currentNode;

                    pq.push({newDistance, neighbor.first});


                }

           }

    }

        if (distances[end] == INT_MAX)

            {

            cout << "No path exists from " << start << " to " << end << ".\n";
            return;

            }

        cout << "Optimal route from \"" << start << "\" to \"" << end << "\":\n";
        vector<string> path;

        string pathNode = end;

        while (pathNode != start)

            {

            path.push_back(pathNode);

            pathNode = previous[pathNode];

        }

        path.push_back(start);

        reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); ++i)

            {

            cout << path[i];

            if (i != path.size() - 1) cout << " -> ";


        }


        cout << "\nTotal Distance: " << distances[end] << " units\n";

    }


   bool removeEdge(const string& source, const string& destination)

    {
        if (adjList.find(source) == adjList.end() || adjList.find(destination) == adjList.end())

            return false;

        auto removeEdgeFromList = [](vector<pair<string, pair<int, TrafficCondition>>>& list, const string& destination)

         {

            list.erase(remove_if(list.begin(), list.end(), [&destination](const pair<string, pair<int, TrafficCondition>>& p)
        {

                return p.first == destination;
            }

            ), list.end());

        };

        removeEdgeFromList(adjList[source], destination);
        removeEdgeFromList(adjList[destination], source);

        return true;

    }

    void updateTrafficCondition(const string& source, const string& destination, TrafficCondition newTraffic) {

        for (auto& neighbor : adjList[source])

            {

            if (neighbor.first == destination)

             {
                neighbor.second.second = newTraffic;

             }

        }
        for (auto& neighbor : adjList[destination])

            {

            if (neighbor.first == source)
            {

                neighbor.second.second = newTraffic;

            }

        }

        cout << "Traffic condition updated between " << source << " and " << destination << ".\n";
    }

    void saveToFile(const string& filename) const

    {

        ofstream file(filename);
        if (!file)

            {

            cout << "Error opening file for writing.\n";

            return;

            }

        for (const auto& node : adjList)
            {
            for (const auto& neighbor : node.second)

                {

                file << node.first << " " << neighbor.first << " " << neighbor.second.first << " "
                     << neighbor.second.second << "\n";
            }

        }

        cout << "Data saved to " << filename << ".\n";
    }

    void loadFromFile(const string& filename)

    {
        ifstream file(filename);
        if (!file)

            {

            cout << "Error opening file for reading.\n";
            return;
        }

        adjList.clear();

        string source, destination;
        int distance, traffic;

        while (file >> source >> destination >> distance >> traffic)

            {

            addEdge(source, destination, distance, static_cast<TrafficCondition>(traffic));

            }

        cout << "Data loaded from " << filename << ".\n";

    }

    void displayAllLocations() const
    {
        cout << "All Locations in the City Network:\n";
        if (adjList.empty())
            {
            cout << "No locations available.\n";
        }
        else

            {

            for (const auto& node : adjList)

             {

                cout << node.first << "\n";  // Display each location (node)

             }
        }
    }

    unordered_map<string, vector<pair<string, pair<int, TrafficCondition>>>> getAdjList() const {

        return adjList;
    }

};

// Class for customer management

class Customer

 {

public:
    string name;
    string contact;
    string city;

    Customer(string n, string c, string ci) : name(n), contact(c), city(ci) {}

    void displayDetails() const

    {
        cout << "Name: " << name << "\nContact: " << contact << "\nCity: " << city << "\n";
    }

};

class CustomerManager

{

private:

    vector<Customer> customers;

public:

    void addCustomer(const string& name, const string& contact, const string& city)

     {
        customers.emplace_back(name, contact, city);

        //cout << "Customer \"" << name << "\" added successfully!\n";
    }

    void displayAllCustomers() const

     {
        if (customers.empty())

            {
            cout << "No customers to display.\n";
            return;
        }
        for (size_t i = 0; i < customers.size(); ++i)

        {
            cout << i + 1 << ". ";
            customers[i].displayDetails();
            cout << "---------------\n";


        }


    }

    Customer* selectCustomer()

     {
        displayAllCustomers();
        if (customers.empty()) return nullptr;

        cout << "Select a customer by number: ";
        int choice;
        cin >> choice;

        if (choice < 1 || choice > static_cast<int>(customers.size()))

            {

            cout << "Invalid selection!\n";
            return nullptr;

        }

        return &customers[choice - 1];
    }
};
// More customers
// Add up to 500 customers as needed following the same format



/*Distance: 150, Traffic: 2)
Aurangabad -> (Pune, Distance: 230, Traffic: 1) (Bidar City Center, Distance: 180, Traffic: 2) (Bidar City Center, Distance: 180, Traffic: 1)
Pandavapura -> (Mandya, Distance: 18, Traffic: 0)

Shirdi -> (Pune, Distance: 210, Traffic: 0)

Yelahanka -> (Bengaluru, Distance: 20, Traffic: 0) (Mandya, Distance: 90, Traffic: 1) (Tumkur, Distance: 100, Traffic: 0)
Kalyan -> (Pune, Distance: 140, Traffic: 0)
Karad -> (Pune, Distance: 180, Traffic: 0)


Chinchwad -> (Pune, Distance: 10, Traffic: 0)
Dapodi -> (Pune, Distance: 12, Traffic: 0)


Main Menu
1. Add Location and Road

2. Find Optimal Route
3. Display City Network

4. Manage Customers
5. Exit


Enter your choice: 2

Enter start location: Dapodi
Enter end location: Pnue

Error: One or both locations are not in the network.


Main Menu
1. Add Location and Road

2. Find Optimal Route
3. Display City Network

4. Manage Customers
5. Exit

Enter your choice: 2
Enter start location: Dapodi

Enter end location: Pune
Optimal route from "Dapodi" to "Pune":

Dapodi -> Pune
Total Distance: 12 units


Main Menu
1. Add Location and Road

2. Find Optimal Route
3. Display City Network

4. Manage Customers*/

// Main program
void optimalRoutePlanning() {
      CityGraph cityGraph;
    CustomerManager customerManager;

    // Predefined customers
    customerManager.addCustomer("Nico", "555-555-0316", "Raichur");

    customerManager.addCustomer("Oscar", "555-555-0317", "Mandya");

    customerManager.addCustomer("Peyton", "555-555-0318", "Vijaypur");

    customerManager.addCustomer("Quinn", "555-555-0319", "Udupi");

    customerManager.addCustomer("Alice", "123-456-7890", "Downtown");

    customerManager.addCustomer("Bob", "987-654-3210", "Uptown");

    customerManager.addCustomer("Charlie", "555-555-5555", "Midtown");

    customerManager.addCustomer("Diana", "111-222-3333", "Suburbs");

    customerManager.addCustomer("Alice", "123-456-7890", "Raichur");

    customerManager.addCustomer("Bob", "987-654-3210", "Vijaypur");

    customerManager.addCustomer("Charlie", "555-555-5555", "Mysore");

    customerManager.addCustomer("Diana", "111-222-3333", "Gadag");

    customerManager.addCustomer("Eve", "222-333-4444", "Tumkur");

    customerManager.addCustomer("Frank", "333-444-5555", "Belagavi");

    customerManager.addCustomer("Grace", "444-555-6666", "Hassan");

    customerManager.addCustomer("Hank", "555-666-7777", "Mandya");

    customerManager.addCustomer("Ivy", "666-777-8888", "Bangalore");

    customerManager.addCustomer("Jack", "777-888-9999", "Raichur");

    customerManager.addCustomer("Kara", "888-999-0000", "Vijaypur");

    customerManager.addCustomer("Leo", "999-000-1111", "Mysore");

    customerManager.addCustomer("Mia", "111-000-2222", "Gadag");

    customerManager.addCustomer("Nina", "222-000-3333", "Tumkur");

    customerManager.addCustomer("Oscar", "333-000-4444", "Belagavi");

    customerManager.addCustomer("Paul", "444-000-5555", "Hassan");

    customerManager.addCustomer("Quinn", "555-000-6666", "Mandya");

    customerManager.addCustomer("Rachel", "666-000-7777", "Bangalore");

    customerManager.addCustomer("Sam", "777-000-8888", "Raichur");

    customerManager.addCustomer("Tina", "888-000-9999", "Vijaypur");

    customerManager.addCustomer("Uma", "999-111-0000", "Mysore");

    customerManager.addCustomer("Vera", "111-111-1111", "Gadag");

    customerManager.addCustomer("Walt", "222-111-1111", "Tumkur");

    customerManager.addCustomer("Xander", "333-111-1111", "Belagavi");

    customerManager.addCustomer("Yara", "444-111-1111", "Hassan");

    customerManager.addCustomer("Zane", "555-111-1111", "Mandya");

    customerManager.addCustomer("Amara", "666-111-1111", "Bangalore");

    customerManager.addCustomer("Ben", "777-111-1111", "Raichur");

    customerManager.addCustomer("Cora", "888-111-1111", "Vijaypur");

    customerManager.addCustomer("Derek", "999-111-1111", "Mysore");

    customerManager.addCustomer("Eva", "111-222-4444", "Gadag");

    customerManager.addCustomer("Finn", "222-333-5555", "Tumkur");

    customerManager.addCustomer("Gina", "333-444-6666", "Belagavi");

    customerManager.addCustomer("Hugo", "444-555-7777", "Hassan");

    customerManager.addCustomer("Iris", "555-666-8888", "Mandya");

    customerManager.addCustomer("Jake", "666-777-9999", "Bangalore");

    customerManager.addCustomer("Kelsey", "777-888-0000", "Raichur");

    customerManager.addCustomer("Liam", "888-999-1111", "Vijaypur");

    customerManager.addCustomer("Maya", "999-000-2222", "Mysore");

    customerManager.addCustomer("Noah", "111-222-3333", "Gadag");

    customerManager.addCustomer("Olivia", "222-333-4444", "Tumkur");

    customerManager.addCustomer("Pauline", "333-444-5555", "Belagavi");

    customerManager.addCustomer("Quincy", "444-555-6666", "Hassan");

    customerManager.addCustomer("Rita", "555-666-7777", "Mandya");

    customerManager.addCustomer("Steve", "666-777-8888", "Bangalore");

    customerManager.addCustomer("Travis", "777-888-9999", "Raichur");

    customerManager.addCustomer("Ursula", "888-999-0000", "Vijaypur");

    customerManager.addCustomer("Violet", "999-000-1111", "Mysore");

    customerManager.addCustomer("Will", "111-111-2222", "Gadag");

    customerManager.addCustomer("Xena", "222-111-3333", "Tumkur");

    customerManager.addCustomer("Yvonne", "333-111-4444", "Belagavi");

    customerManager.addCustomer("Zoe", "444-111-5555", "Hassan");

    customerManager.addCustomer("Adam", "555-111-6666", "Mandya");

    customerManager.addCustomer("Bella", "666-111-7777", "Bangalore");

    customerManager.addCustomer("Chris", "777-111-8888", "Raichur");

    customerManager.addCustomer("Diana", "888-111-9999", "Vijaypur");

    customerManager.addCustomer("Evan", "999-111-0000", "Mysore");

    customerManager.addCustomer("Fiona", "111-222-1111", "Gadag");

    customerManager.addCustomer("Greg", "222-333-2222", "Tumkur");

    customerManager.addCustomer("Helen", "333-444-3333", "Belagavi");

    customerManager.addCustomer("Ian", "444-555-4444", "Hassan");

    customerManager.addCustomer("Julia", "555-666-5555", "Mandya");

    customerManager.addCustomer("Kevin", "666-777-6666", "Bangalore");

    customerManager.addCustomer("Laura", "777-888-7777", "Raichur");

    customerManager.addCustomer("Mike", "888-999-8888", "Vijaypur");

    customerManager.addCustomer("Nina", "999-000-9999", "Mysore");

    customerManager.addCustomer("Oscar", "111-111-0000", "Gadag");

    customerManager.addCustomer("Pat", "222-222-1111", "Tumkur");

    customerManager.addCustomer("Quinn", "333-333-2222", "Belagavi");

    customerManager.addCustomer("Rachel", "444-444-3333", "Hassan");

    customerManager.addCustomer("Sam", "555-555-4444", "Mandya");

    customerManager.addCustomer("Tina", "666-666-5555", "Bangalore");

    customerManager.addCustomer("Ursula", "777-777-6666", "Raichur");

    customerManager.addCustomer("Vicky", "888-888-7777", "Vijaypur");

    customerManager.addCustomer("Wendy", "999-999-8888", "Mysore");

    customerManager.addCustomer("Xander", "111-111-9999", "Gadag");

    customerManager.addCustomer("Yara", "222-222-0000", "Tumkur");

    customerManager.addCustomer("Zane", "333-333-1111", "Belagavi");

    customerManager.addCustomer("Alice", "123-456-7890", "Raichur");

    customerManager.addCustomer("Bob", "987-654-3210", "Vijaypur");

    customerManager.addCustomer("Charlie", "555-555-5555", "Mysore");

    customerManager.addCustomer("Diana", "111-222-3333", "Gadag");

    customerManager.addCustomer("Eve", "222-333-4444", "Tumkur");

    customerManager.addCustomer("Frank", "333-444-5555", "Belagavi");

    customerManager.addCustomer("Grace", "444-555-6666", "Hassan");

    customerManager.addCustomer("Hank", "555-666-7777", "Mandya");

    customerManager.addCustomer("Ivy", "666-777-8888", "Bangalore");

    customerManager.addCustomer("Jack", "777-888-9999", "Raichur");

    customerManager.addCustomer("Kara", "888-999-0000", "Vijaypur");

    customerManager.addCustomer("Leo", "999-000-1111", "Mysore");

    customerManager.addCustomer("Mia", "111-000-2222", "Gadag");

    customerManager.addCustomer("Nina", "222-000-3333", "Tumkur");

    customerManager.addCustomer("Oscar", "333-000-4444", "Belagavi");


customerManager.addCustomer("Paul", "444-000-5555", "Hassan");
customerManager.addCustomer("Quinn", "555-000-6666", "Mandya");

customerManager.addCustomer("Rachel", "666-000-7777", "Bangalore");
customerManager.addCustomer("Sam", "777-000-8888", "Raichur");

customerManager.addCustomer("Tina", "888-000-9999", "Vijaypur");


customerManager.addCustomer("Uma", "999-111-0000", "Mysore");
customerManager.addCustomer("Vera", "111-111-1111", "Gadag");

customerManager.addCustomer("Walt", "222-111-1111", "Tumkur");
customerManager.addCustomer("Xander", "333-111-1111", "Belagavi");

customerManager.addCustomer("Yara", "444-111-1111", "Hassan");
customerManager.addCustomer("Zane", "555-111-1111", "Mandya");

customerManager.addCustomer("Amara", "666-111-1111", "Bangalore");
customerManager.addCustomer("Ben", "777-111-1111", "Raichur");

customerManager.addCustomer("Cora", "888-111-1111", "Vijaypur");

customerManager.addCustomer("Derek", "999-111-1111", "Mysore");


customerManager.addCustomer("Eva", "111-222-4444", "Gadag");

customerManager.addCustomer("Finn", "222-333-5555", "Tumkur");
customerManager.addCustomer("Gina", "333-444-6666", "Belagavi");

customerManager.addCustomer("Hugo", "444-555-7777", "Hassan");
customerManager.addCustomer("Iris", "555-666-8888", "Mandya");

customerManager.addCustomer("Jake", "666-777-9999", "Bangalore");
customerManager.addCustomer("Kelsey", "777-888-0000", "Raichur");

customerManager.addCustomer("Liam", "888-999-1111", "Vijaypur");
customerManager.addCustomer("Maya", "999-000-2222", "Mysore");

customerManager.addCustomer("Noah", "111-222-3333", "Gadag");


customerManager.addCustomer("Olivia", "222-333-4444", "Tumkur");
customerManager.addCustomer("Pauline", "333-444-5555", "Belagavi");

customerManager.addCustomer("Quincy", "444-555-6666", "Hassan");
customerManager.addCustomer("Rita", "555-666-7777", "Mandya");

customerManager.addCustomer("Steve", "666-777-8888", "Bangalore");
customerManager.addCustomer("Travis", "777-888-9999", "Raichur");

customerManager.addCustomer("Ursula", "888-999-0000", "Vijaypur");
customerManager.addCustomer("Violet", "999-000-1111", "Mysore");

customerManager.addCustomer("Will", "111-111-2222", "Gadag");
customerManager.addCustomer("Xena", "222-111-3333", "Tumkur");


customerManager.addCustomer("Yvonne", "333-111-4444", "Belagavi");

customerManager.addCustomer("Zoe", "444-111-5555", "Hassan");

customerManager.addCustomer("Adam", "555-111-6666", "Mandya");
customerManager.addCustomer("Bella", "666-111-7777", "Bangalore");

customerManager.addCustomer("Chris", "777-111-8888", "Raichur");
customerManager.addCustomer("Diana", "888-111-9999", "Vijaypur");

customerManager.addCustomer("Evan", "999-111-0000", "Mysore");

customerManager.addCustomer("Fiona", "111-222-1111", "Gadag");

customerManager.addCustomer("Greg", "222-333-2222", "Tumkur");



customerManager.addCustomer("Helen", "333-444-3333", "Belagavi");

customerManager.addCustomer("Ian", "444-555-4444", "Hassan");

customerManager.addCustomer("Julia", "555-666-5555", "Mandya");

customerManager.addCustomer("Kevin", "666-777-6666", "Bangalore");

customerManager.addCustomer("Laura", "777-888-7777", "Raichur");

customerManager.addCustomer("Mike", "888-999-8888", "Vijaypur");
customerManager.addCustomer("Nina", "999-000-9999", "Mysore");

customerManager.addCustomer("Oscar", "111-111-0000", "Gadag");
customerManager.addCustomer("Pat", "222-222-1111", "Tumkur");

customerManager.addCustomer("Quinn", "333-333-2222", "Belagavi");



customerManager.addCustomer("Rachel", "444-444-3333", "Hassan");

customerManager.addCustomer("Sam", "555-555-4444", "Mandya");

customerManager.addCustomer("Tina", "666-666-5555", "Bangalore");
customerManager.addCustomer("Ursula", "777-777-6666", "Raichur");

customerManager.addCustomer("Vicky", "888-888-7777", "Vijaypur");
customerManager.addCustomer("Wendy", "999-999-8888", "Mysore");

customerManager.addCustomer("Xander", "111-111-9999", "Gadag");

customerManager.addCustomer("Yara", "222-222-0000", "Tumkur");

customerManager.addCustomer("Zane", "333-333-1111", "Belagavi");

customerManager.addCustomer("Iris", "555-555-1234", "Belagavi");
customerManager.addCustomer("Jack", "555-555-5678", "Mysore");

customerManager.addCustomer("Kara", "555-555-9876", "Tumkur");
customerManager.addCustomer("Leo", "555-555-1122", "Hassan");

customerManager.addCustomer("Mia", "555-555-3344", "Bangalore");

customerManager.addCustomer("Noah", "555-555-5566", "Raichur");
customerManager.addCustomer("Olivia", "555-555-7788", "Mandya");

customerManager.addCustomer("Paul", "555-555-9900", "Vijaypur");
customerManager.addCustomer("Quinn", "555-555-2233", "Udupi");

customerManager.addCustomer("Riley", "555-555-4455", "Dharwad");


customerManager.addCustomer("Sophie", "555-555-6677", "Belagavi");
customerManager.addCustomer("Tom", "555-555-8899", "Mysore");

customerManager.addCustomer("Uma", "555-555-1234", "Tumkur");
customerManager.addCustomer("Victor", "555-555-5678", "Hassan");

customerManager.addCustomer("Wendy", "555-555-9876", "Bangalore");
customerManager.addCustomer("Xander", "555-555-1122", "Raichur");
customerManager.addCustomer("Yara", "555-555-3344", "Mandya");

customerManager.addCustomer("Zane", "555-555-5566", "Vijaypur");
customerManager.addCustomer("Aidan", "555-555-7788", "Udupi");

customerManager.addCustomer("Bella", "555-555-9900", "Dharwad");


customerManager.addCustomer("Caden", "555-555-2233", "Belagavi");
customerManager.addCustomer("Dylan", "555-555-4455", "Mysore");

customerManager.addCustomer("Ella", "555-555-6677", "Tumkur");
customerManager.addCustomer("Finn", "555-555-8899", "Hassan");

customerManager.addCustomer("Grace", "555-555-1234", "Bangalore");

customerManager.addCustomer("Hugo", "555-555-5678", "Raichur");

customerManager.addCustomer("Ivy", "555-555-9876", "Mandya");
customerManager.addCustomer("Jasper", "555-555-1122", "Vijaypur");

customerManager.addCustomer("Kira", "555-555-3344", "Udupi");

customerManager.addCustomer("Liam", "555-555-5566", "Dharwad");


customerManager.addCustomer("Maya", "555-555-7788", "Belagavi");

customerManager.addCustomer("Nina", "555-555-9900", "Mysore");
customerManager.addCustomer("Oscar", "555-555-2233", "Tumkur");

customerManager.addCustomer("Penny", "555-555-4455", "Hassan");
customerManager.addCustomer("Quincy", "555-555-6677", "Bangalore");

customerManager.addCustomer("Rory", "555-555-8899", "Raichur");

customerManager.addCustomer("Sam", "555-555-1234", "Mandya");

customerManager.addCustomer("Tina", "555-555-5678", "Vijaypur");
customerManager.addCustomer("Ursula", "555-555-9876", "Udupi");

customerManager.addCustomer("Vera", "555-555-1122", "Dharwad");



customerManager.addCustomer("Will", "555-555-3344", "Belagavi");

customerManager.addCustomer("Xena", "555-555-5566", "Mysore");
customerManager.addCustomer("Yvonne", "555-555-7788", "Tumkur");

customerManager.addCustomer("Zane", "555-555-9900", "Hassan");

customerManager.addCustomer("Alex", "555-555-2233", "Bangalore");

customerManager.addCustomer("Beth", "555-555-4455", "Raichur");

customerManager.addCustomer("Charlie", "555-555-6677", "Mandya");

customerManager.addCustomer("Diana", "555-555-8899", "Vijaypur");

customerManager.addCustomer("Elliot", "555-555-1234", "Udupi");

customerManager.addCustomer("Aaron", "555-555-0001", "Belagavi");

customerManager.addCustomer("Brandon", "555-555-0002", "Mysore");
customerManager.addCustomer("Cameron", "555-555-0003", "Tumkur");

customerManager.addCustomer("Dylan", "555-555-0004", "Hassan");
customerManager.addCustomer("Ethan", "555-555-0005", "Bangalore");

customerManager.addCustomer("Frank", "555-555-0006", "Raichur");
customerManager.addCustomer("Gavin", "555-555-0007", "Mandya");

customerManager.addCustomer("Harrison", "555-555-0008", "Vijaypur");
customerManager.addCustomer("Ian", "555-555-0009", "Udupi");

customerManager.addCustomer("James", "555-555-0010", "Dharwad");



customerManager.addCustomer("Kyle", "555-555-0011", "Belagavi");
customerManager.addCustomer("Leo", "555-555-0012", "Mysore");

customerManager.addCustomer("Mason", "555-555-0013", "Tumkur");
customerManager.addCustomer("Nash", "555-555-0014", "Hassan");

customerManager.addCustomer("Owen", "555-555-0015", "Bangalore");
customerManager.addCustomer("Peter", "555-555-0016", "Raichur");

customerManager.addCustomer("Quinton", "555-555-0017", "Mandya");
customerManager.addCustomer("Ryan", "555-555-0018", "Vijaypur");

customerManager.addCustomer("Sam", "555-555-0019", "Udupi");
customerManager.addCustomer("Tyler", "555-555-0020", "Dharwad");



customerManager.addCustomer("Ulysses", "555-555-0021", "Belagavi");
customerManager.addCustomer("Vince", "555-555-0022", "Mysore");

customerManager.addCustomer("Willow", "555-555-0023", "Tumkur");
customerManager.addCustomer("Xander", "555-555-0024", "Hassan");

customerManager.addCustomer("Yvonne", "555-555-0025", "Bangalore");
customerManager.addCustomer("Zane", "555-555-0026", "Raichur");
customerManager.addCustomer("Amos", "555-555-0027", "Mandya");

customerManager.addCustomer("Beau", "555-555-0028", "Vijaypur");
customerManager.addCustomer("Charles", "555-555-0029", "Udupi");

customerManager.addCustomer("Dale", "555-555-0030", "Dharwad");



customerManager.addCustomer("Eli", "555-555-0031", "Belagavi");
customerManager.addCustomer("Felix", "555-555-0032", "Mysore");

customerManager.addCustomer("Gage", "555-555-0033", "Tumkur");
customerManager.addCustomer("Hunter", "555-555-0034", "Hassan");

customerManager.addCustomer("Isaac", "555-555-0035", "Bangalore");
customerManager.addCustomer("Jack", "555-555-0036", "Raichur");

customerManager.addCustomer("Kane", "555-555-0037", "Mandya");
customerManager.addCustomer("Levi", "555-555-0038", "Vijaypur");

customerManager.addCustomer("Myles", "555-555-0039", "Udupi");

customerManager.addCustomer("Nolan", "555-555-0040", "Dharwad");


customerManager.addCustomer("Oscar", "555-555-0041", "Belagavi");

customerManager.addCustomer("Perry", "555-555-0042", "Mysore");
customerManager.addCustomer("Quinn", "555-555-0043", "Tumkur");

customerManager.addCustomer("Ryder", "555-555-0044", "Hassan");
customerManager.addCustomer("Spencer", "555-555-0045", "Bangalore");

customerManager.addCustomer("Theo", "555-555-0046", "Raichur");

customerManager.addCustomer("Urie", "555-555-0047", "Mandya");
customerManager.addCustomer("Vaughn", "555-555-0048", "Vijaypur");

customerManager.addCustomer("Wyatt", "555-555-0049", "Udupi");

customerManager.addCustomer("Zion", "555-555-0050", "Dharwad");


customerManager.addCustomer("Aiden", "555-555-0051", "Belagavi");

customerManager.addCustomer("Blaise", "555-555-0052", "Mysore");
customerManager.addCustomer("Carl", "555-555-0053", "Tumkur");

customerManager.addCustomer("Devin", "555-555-0054", "Hassan");
customerManager.addCustomer("Ezra", "555-555-0055", "Bangalore");

customerManager.addCustomer("Finn", "555-555-0056", "Raichur");
customerManager.addCustomer("Gabe", "555-555-0057", "Mandya");

customerManager.addCustomer("Hunter", "555-555-0058", "Vijaypur");
customerManager.addCustomer("Ian", "555-555-0059", "Udupi");

customerManager.addCustomer("Jaxon", "555-555-0060", "Dharwad");

customerManager.addCustomer("Kaden", "555-555-0061", "Belagavi");

customerManager.addCustomer("Landon", "555-555-0062", "Mysore");
customerManager.addCustomer("Milo", "555-555-0063", "Tumkur");
customerManager.addCustomer("Nash", "555-555-0064", "Hassan");

customerManager.addCustomer("Omar", "555-555-0065", "Bangalore");
customerManager.addCustomer("Pace", "555-555-0066", "Raichur");

customerManager.addCustomer("Quentin", "555-555-0067", "Mandya");
customerManager.addCustomer("Reed", "555-555-0068", "Vijaypur");

customerManager.addCustomer("Seth", "555-555-0069", "Udupi");
customerManager.addCustomer("Toby", "555-555-0070", "Dharwad");


customerManager.addCustomer("Ulysses", "555-555-0071", "Belagavi");
customerManager.addCustomer("Vito", "555-555-0072", "Mysore");
customerManager.addCustomer("Will", "555-555-0073", "Tumkur");

customerManager.addCustomer("Xander", "555-555-0074", "Hassan");
customerManager.addCustomer("Yale", "555-555-0075", "Bangalore");

customerManager.addCustomer("Zeke", "555-555-0076", "Raichur");
customerManager.addCustomer("Alex", "555-555-0077", "Mandya");

customerManager.addCustomer("Bryce", "555-555-0078", "Vijaypur");
customerManager.addCustomer("Carter", "555-555-0079", "Udupi");

customerManager.addCustomer("Dante", "555-555-0080", "Dharwad");

    cout << "Welcome to the Traffic Management System!\n";

    while (true) {
        cout << "\nMain Menu\n";

        cout << "1. Add Location and Road\n";

        cout << "2. Find Optimal Route\n";

        cout << "3. Display City Network\n";

        cout << "4. Select Customer and Travel\n";

        cout << "5. Exit\n";

        cout << "6. Remove Road\n";

        cout << "7. Add Customer\n";

        cout << "8. Display All Customers\n";

        cout << "9. Display All Locations\n";

        cout << "10. Find Optimal Route for Customer\n";

        cout << "11. Select Vehicle Type for Route\n";

        cout << "12. Update Traffic Condition\n";

        cout << "13. Save Data to File\n";

        cout << "14. Load Data from File\n";

        cout << "Enter your choice: ";



        int choice;
        cin >> choice;


        if (choice == 5)
            {
            cout << "Exiting system. Goodbye!\n";
            break;
        }

        switch (choice)
        {
            case 1:
                {
                string source, destination;
                int distance, traffic;
                cout << "Enter source location: ";
                cin >> source;

                cout << "Enter destination location: ";
                cin >> destination;

                cout << "Enter distance: ";
                cin >> distance;

                cout << "Enter traffic condition (0 = LIGHT, 1 = MODERATE, 2 = HEAVY): ";
                cin >> traffic;

                cityGraph.addEdge(source, destination, distance, static_cast<TrafficCondition>(traffic));
                cout << "Road added successfully!\n";

                break;

            }
            case 2:
                {
                string start, end;
                cout << "Enter start location: ";
                cin >> start;

                cout << "Enter end location: ";
                cin >> end;

                cityGraph.findOptimalRoute(start, end);
                break;

            }
            case 3:
                cityGraph.printGraph();
                break;
            case 4: {
                Customer* customer = customerManager.selectCustomer();
                if (!customer) break;

                cout << "\nSelected Customer:\n";
                customer->displayDetails();

                string source, destination, vehicleType;
                cout << "Enter source location: ";

                cin >> source;

                cout << "Enter destination location: ";
                cin >> destination;

                cout << "Enter vehicle type: ";
                cin >> vehicleType;

                cout << "\nTravel Summary:\n";
                cout << "Customer: " << customer->name << "\n";

                cout << "Vehicle: " << vehicleType << "\n";

                cityGraph.findOptimalRoute(source, destination);

                break;
            }


            case 6: {

                string source, destination;
                cout << "Enter source location: ";

                cin >> source;

                cout << "Enter destination location: ";
                cin >> destination;



                bool roadRemoved = cityGraph.removeEdge(source, destination);

                if (roadRemoved)
                    {
                    cout << "Road between " << source << " and " << destination << " removed successfully.\n";

                } else

                 {

                    cout << "No such road exists between " << source << " and " << destination << ".\n";
                }
                break;
            }
            case 7:

                 {
                string name, contact, city;
                cout << "Enter customer name: ";

                cin >> name;
                cout << "Enter customer contact number: ";

                cin >> contact;

                cout << "Enter customer city: ";

                cin >> city;



                customerManager.addCustomer(name, contact, city);

                break;
            }


            case 8:

                {

                customerManager.displayAllCustomers();
                break;

            }

            case 9:
                {

                cityGraph.displayAllLocations();
                break;
            }
            case 10:
                 {
                string start, end;

                cout << "Enter start location: ";
                cin >> start;

                cout << "Enter end location: ";
                cin >> end;

                cityGraph.findOptimalRoute(start, end);
                break;
            }

            case 11: {
        string start, end;
        int vehicleChoice;

        cout << "Enter start location: ";

        cin >> start;

        cout << "Enter end location: ";

        cin >> end;

        cout << "Choose vehicle type (0=CAR, 1=TRUCK, 2=MOTORBIKE): ";

        cin >> vehicleChoice;

        // Here you would implement route based on vehicle type

        break;
    }
            case 12: {

                string source, destination;
                int newTrafficCondition;

                cout << "Enter source location: ";

                cin >> source;

                cout << "Enter destination location: ";

                cin >> destination;

                cout << "Enter new traffic condition (0 = LIGHT, 1 = MODERATE, 2 = HEAVY): ";

                cin >> newTrafficCondition;

                cityGraph.updateTrafficCondition(source, destination, static_cast<TrafficCondition>(newTrafficCondition));

                break;

            }

            case 13: {

                string filename;

                cout << "Enter filename to save data: ";

                cin >> filename;

                cityGraph.saveToFile(filename);

                break;

            }

            case 14: {

                string filename;

                cout << "Enter filename to load data from: ";

                cin >> filename;

                cityGraph.loadFromFile(filename);

                break;

            }

            default:

                cout << "Invalid choice! Try again.\n";


        }
    }






    //return 0;
    }

void generateTrafficDensity()
{
    trafficDensity = rand() % 101;  // Random density between 0 and 100
    cout << "Traffic Density: " << trafficDensity << "%" << endl;
}

// Function to simulate weather based on traffic
void simulateWeather()

{
    if (trafficDensity > 70)

        {
        temperature += 5; // Higher temperature due to heavy traffic
        humidity += 10;   // Increased humidity with high traffic
        pollutionLevel += 15;  // Increased pollution with high traffic
        weatherCondition = "Smoggy";
    }
    else if (trafficDensity < 30)
        {
        temperature -= 3; // Lower temperature with less traffic
        humidity -= 5;    // Decreased humidity with less traffic
        pollutionLevel -= 5; // Decreased pollution
        weatherCondition = "Clear";
    }
    else
        {
        temperature += 2;
        humidity += 2;
        pollutionLevel += 5; // Moderate pollution with moderate traffic
        weatherCondition = "Partly Cloudy";

       }

    // Display the simulated weather based on traffic density
    cout << "Current Weather: " << weatherCondition << endl;
    cout << "Temperature: " << temperature << "°C" << endl;
    cout << "Humidity: " << humidity << "%" << endl;
    cout << "Pollution Level: " << pollutionLevel << "%" << endl;

}

// Function to simulate random weather effects
void randomWeatherEffects()
{
    int randomEffect = rand() % 5; // Random number between 0 and 4
    if (randomEffect == 0)
        {
        cout << "Clear weather. No rain." << endl;
        }
    else if (randomEffect == 1)
        {
        cout << "Light rain expected." << endl;
        temperature -= 2;
    }
    else if (randomEffect == 2)
        {
        cout << "Heavy rain expected. Traffic may slow down further." << endl;
        temperature -= 4;
        humidity += 20;
    }
    else if (randomEffect == 3)
        {
        cout << "Snowstorm expected. Temperature will drop significantly." << endl;
        temperature -= 10;
        humidity += 30;
        weatherCondition = "Snowstorm";
    }
    else
        {
        cout << "Foggy conditions. Visibility reduced." << endl;
        temperature -= 1;
        humidity += 15;
        weatherCondition = "Foggy";


        }
}

// Function to simulate hourly changes in weather and traffic
void hourlyWeatherChange(int hour)
{
    cout << "\nHour " << hour << " Weather and Traffic Update:" << endl;
    generateTrafficDensity();
    simulateWeather();
    randomWeatherEffects();
}

// Function to predict the next few hours of weather
void forecastWeather(int hours)

{
    cout << "\nForecast for the next " << hours << " hours:" << endl;
    for (int i = 1; i <= hours; i++)
        {
        cout << "\nHour " << i << ": ";
        int forecastTraffic = rand() % 101;
        cout << "Traffic Density: " << forecastTraffic << "%" << endl;
        if (forecastTraffic > 70)
        {
            cout << "Heavy traffic, expect high temperatures and pollution." << endl;
        }
    else if (forecastTraffic < 30)
        {
            cout << "Light traffic, expect cooler temperatures and lower pollution." << endl;
        }

    else
        {
            cout << "Moderate traffic, mild weather expected." << endl;
        }

    }
}

// Function to simulate a long-term weather pattern over multiple days
void dailyWeatherSimulation(int days)
{
    for (int day = 1; day <= days; day++)

        {
        cout << "\nDay " << day << " Weather and Traffic Update:" << endl;
        generateTrafficDensity();
        simulateWeather();
        randomWeatherEffects();

    }
}

// Function to display the current weather report
void displayWeatherReport()

 {
    cout << "\nCurrent Weather Report:" << endl;
    cout << "Temperature: " << temperature << "°C" << endl;
    cout << "Humidity: " << humidity << "%" << endl;
    cout << "Pollution Level: " << pollutionLevel << "%" << endl;
    cout << "Current Condition: " << weatherCondition << endl;
}



void increasingNetworkCoverage() {
   srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation


    int choice, hours, days;

    // Main menu for the weather simulation
    do
        {
        cout << "\nWeather Simulation Menu:" << endl;
        cout << "1. Simulate Hourly Weather Changes" << endl;
        cout << "2. Forecast Weather for the Next Few Hours" << endl;
        cout << "3. Simulate Daily Weather Over Multiple Days" << endl;
        cout << "4. Display Current Weather Report" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice)

        {
            case 1:
                cout << "Enter the hour (1-24): ";
                cin >> hours;
                hourlyWeatherChange(hours);

                break;

            case 2:
                cout << "Enter the number of hours to forecast: ";
                cin >> hours;
                forecastWeather(hours);

                break;

            case 3:
                cout << "Enter the number of days to simulate: ";
                cin >> days;
                dailyWeatherSimulation(days);

                break;

            case 4:
                displayWeatherReport();

                break;

            case 5:
                cout << "Exiting the simulation..." << endl;

                break;

            default:
                cout << "Invalid choice. Please try again." << endl;

        }

    }
    while (choice != 5);

    //return 0;
}


void dynamicSignalTiming()

{
    map<string, int> trafficData;

    int numRoads;

    cout << "Enter the number of roads: ";
    while (!(cin >> numRoads) || numRoads <= 0)

        {

        cout << "Please enter a valid positive integer for the number of roads: ";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input


        }

    for (int i = 0; i < numRoads; i++)

        {
        string roadName;
        int trafficVolume;

        cout << "Enter the name of road " << i + 1 << ": ";
        cin >> roadName;

        cout << "Enter traffic volume for " << roadName << ": ";

        while (!(cin >> trafficVolume) || trafficVolume < 0)

            {
            cout << "Please enter a valid non-negative integer for traffic volume: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            }

        trafficData[roadName] = trafficVolume;

    }

    // Customizable duration calculation

    double durationFactor;
    cout << "Enter the duration factor (seconds per unit of traffic volume): ";
    while (!(cin >> durationFactor) || durationFactor <= 0) {
        cout << "Please enter a valid positive number for the duration factor: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

    cout << "\nDynamic Signal Timing Based on Real-Time Traffic Data:\n";
    double totalTrafficVolume = 0;
    double totalDuration = 0;

    for (const auto& road : trafficData)

        {

        int trafficVolume = road.second;
        double duration = trafficVolume * durationFactor; // Calculate duration based on user-defined factor
        totalTrafficVolume += trafficVolume;
        totalDuration += duration;

        // Categorize traffic volume

        string category;

        if (trafficVolume < 20)

            {
            category = "Low";
        }

        else if (trafficVolume < 50)

            {
            category = "Medium";
            }
        else
        {

            category = "High";

        }

        // Convert duration from seconds to minutes

        double durationInMinutes = duration / 60;

        cout << "Green light for " << road.first << ": " << fixed << setprecision(2)
             << durationInMinutes << " minutes (Traffic Volume: " << trafficVolume << ", Category: " << category << ")\n";

    }

    // Calculate and display totals and averages

    double averageDuration = totalDuration / numRoads;
    double averageDurationInMinutes = averageDuration / 60;  // Convert average duration to minutes


    cout << "\nTotal Traffic Volume: " << totalTrafficVolume << "\n";
    cout << "Average Green Light Duration: " << fixed << setprecision(2) << averageDurationInMinutes << " minutes\n";
    cout << "-----------------------------------\n";


}

// 2. Pedestrian Crossing Integration

void pedestrianSignal()
 {

    int vehicleCount;

    // Input validation for vehicle count

    cout << "Enter vehicle count: ";
    while (!(cin >> vehicleCount) || vehicleCount < 0)
        {

        cout << "Please enter a valid non-negative integer for vehicle count: ";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

    }

    // Determine pedestrian signal time based on vehicle count

    int pedestrianTime;

    if (vehicleCount > 50)
        {

        pedestrianTime = 30; // Longer time for high vehicle count
        cout << "High vehicle count detected. ";
    }

    else


        {

        pedestrianTime = 15; // Shorter time for low vehicle count
        cout << "Low vehicle count detected. ";

        }

    cout << "Pedestrian Signal Active for " << pedestrianTime << " seconds\n";

}


// 3. Emergency Vehicle Priority

void emergencyVehicleSignal()

 {

    bool emergencyDetected;
    int vehicleCount;

    // Input validation for emergency vehicle detection

    cout << "Is there an emergency vehicle? (1 for Yes, 0 for No): ";

    while (!(cin >> emergencyDetected) || (emergencyDetected != 0 && emergencyDetected != 1))
        {

         cout << "Please enter 1 for Yes or 0 for No: ";
         cin.clear(); // Clear the error flag
         cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }

    if (emergencyDetected)

        {

        cout << "Emergency Vehicle Detected!\n";

        // Input for the number of emergency vehicles

        cout << "Enter the number of emergency vehicles: ";
        while (!(cin >> vehicleCount) || vehicleCount <= 0)
            {

            cout << "Please enter a valid positive integer for the number of emergency vehicles: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

            }

        // Determine signal duration based on the number of emergency vehicles

        int signalDuration = 10 + (vehicleCount * 5); // Base duration + additional time per vehicle
        cout << "Green Signal Activated Immediately for " << signalDuration << " seconds.\n";
        cout << "Please be aware that normal traffic flow will be interrupted during this time.\n";

    }

     else

        {
        cout << "Normal Traffic Flow.\n";

        }

 }

// 4. Adaptive Traffic Light Synchronization
// Function to simulate real-time traffic data for each intersection

map<int, int> getTrafficVolume(int intersections)

{
    map<int, int> trafficData;

    for (int i = 1; i <= intersections; i++)
        {

        trafficData[i] = rand() % 100 + 20;  // Simulated vehicle count for each intersection


    }

    return trafficData;

}

// Function to synchronize traffic lights

void synchronizeTrafficLights()

 {
    int intersections;
    cout << "Enter the number of intersections: ";
    cin >> intersections;

    // Simulate real-time traffic data collection

     map<int, int> trafficData = getTrafficVolume(intersections);


    // Open a log file for storing synchronization details


    ofstream logFile("synchronization_log.txt", ios::app);
    time_t now = time(0);
    char* dt = ctime(&now);
    logFile << "Synchronization started at " << dt << "\n";

    // Synchronize traffic lights based on traffic data

    for (int i = 1; i <= intersections; i++)

        {


        // Check traffic volume for the intersection

        int vehicleCount = trafficData[i];
        int greenDuration = 30;  // Default green light duration

        // Adjust green light duration based on traffic

        if (vehicleCount > 70)
            {

            greenDuration += 15;  // Heavily congested, extend the duration

        }

        else if (vehicleCount < 40)
         {

            greenDuration -= 10;  // Low traffic, shorten the duration

        }

        // Simulate emergency vehicle detection

        bool emergencyVehicleDetected = rand() % 10 < 1;  // 10% chance of emergency vehicle
        if (emergencyVehicleDetected)
        {


            cout << "Emergency vehicle detected at Intersection " << i << "! Extending green light.\n";
            greenDuration += 20;  // Give priority to the emergency vehicle

        }

        // Display synchronization info

        cout << "Intersection " << i << ": Green for " << greenDuration << " seconds, synchronized.\n";

        // Log the synchronization

        logFile << "Intersection " << i << ": Green for " << greenDuration << " seconds, vehicle count: " << vehicleCount << "\n";


        if (emergencyVehicleDetected) {
            logFile << "Emergency vehicle detected at Intersection " << i << "\n";


      }

    }

    // End of synchronization log entry

    logFile << "-----------------------------------\n";
    logFile.close();


}

// 5. Detection of Malfunctioning Traffic Signals

struct TrafficLight
{

    string intersection;
    bool isFunctional;
    string malfunctionDetails;  // Store details if malfunction occurs

};

// Function to simulate real-time malfunction detection

void detectMalfunction()
{

    int numLights;
    cout << "Enter the number of traffic lights to check: ";
    cin >> numLights;

    // Open a log file for storing malfunction details

    ofstream logFile("malfunction_log.txt", ios::app);
    time_t now = time(0);
    char* dt = ctime(&now);

    logFile << "Malfunction Check Started at " << dt << "\n";

    // Array of traffic lights

    TrafficLight lights[numLights];

    for (int i = 0; i < numLights; i++)
        {

        cout << "Enter intersection name for traffic light " << i + 1 << ": ";
        cin >> lights[i].intersection;

        // Randomly simulate malfunction detection
        bool lightStatus = rand() % 2;  // 0 or 1 (simulating malfunction or functional status)

        if (!lightStatus)

            {

            cout << "Traffic light at " << lights[i].intersection << " is malfunctioning!\n";
            cout << "Enter malfunction details (e.g., blinking, off, partial failure): ";
            cin >> lights[i].malfunctionDetails;

            // Log the malfunction

            logFile << "Malfunction detected at Intersection " << lights[i].intersection
                    << ": " << lights[i].malfunctionDetails << "\n";

            // Notify for maintenance

            cout << "Maintenance required for " << lights[i].intersection << "!\n";

        }
         else

         {

            cout << "Traffic light at " << lights[i].intersection << " is functioning properly.\n";
            logFile << "Traffic light at Intersection " << lights[i].intersection << " is functional.\n";

        }

        cout << endl;

    }

    // End of malfunction log entry

    logFile << "-----------------------------------\n";
    logFile.close();

}


// 6. Traffic Density Prediction

void predictTrafficDensity()
 {

    string timeOfDay, dayOfWeek;
    int trafficVolume;

    // Get the time of day

    cout << "Enter the time of day (morning, afternoon, evening, night): ";
    cin >> timeOfDay;

    // Get the day of the week

    cout << "Enter the day of the week (Monday, Tuesday, etc.): ";
    cin >> dayOfWeek;

    // Simulate traffic volume based on time of day and day of the week

    trafficVolume = rand() % 100 + 50;  // Generate a random traffic volume between 50 and 150


    // Log the traffic prediction

    ofstream logFile("traffic_density_log.txt", ios::app);
    time_t now = time(0);
    char* dt = ctime(&now);

    logFile << "Traffic Density Prediction at " << dt << "\n";
    logFile << "Time of Day: " << timeOfDay << ", Day of the Week: " << dayOfWeek << "\n";
    logFile << "Simulated Traffic Volume: " << trafficVolume << "\n";


    // Predict traffic density and adjust signal timing

    if (timeOfDay == "morning" || timeOfDay == "evening")
        {


        cout << "High Traffic Expected. Increase Green Signal Duration.\n";
        logFile << "High Traffic Expected. Green Signal Duration Extended.\n";

    }

    else if (timeOfDay == "afternoon")
     {

        if (trafficVolume > 100)
            {

            cout << "Afternoon Rush. Increase Green Signal Duration.\n";
            logFile << "Afternoon Rush Detected. Green Signal Duration Extended.\n";

        }

         else
        {

            cout << "Moderate Traffic in the Afternoon. Standard Signal Duration.\n";
            logFile << "Moderate Traffic in the Afternoon. Standard Signal Duration.\n";


        }

    }

    else if (timeOfDay == "night")
        {

        cout << "Low Traffic Expected at Night. Standard Signal Duration.\n";
        logFile << "Low Traffic Expected at Night. Standard Signal Duration.\n";

    }

    // Special case for weekends or holidays (e.g., Sunday or public holidays)

    if (dayOfWeek == "Saturday" || dayOfWeek == "Sunday")
        {

        cout << "Weekend Traffic: Expect less congestion.\n";
        logFile << "Weekend Traffic: Expect less congestion.\n";

    }
    else if (dayOfWeek == "Monday" || dayOfWeek == "Friday")
        {

        cout << "High Traffic Due to Weekday Rush.\n";
        logFile << "Weekday Rush Detected. Increase Signal Duration.\n";


    }

    // Log the result and close the log file

    logFile << "-----------------------------------\n";

    logFile.close();

}

// 7. Lane-Specific Signal Control

struct LaneData

{

    int vehicleCount;
    int truckCount;
    int carCount;
    int bikeCount;
    string laneType;

};


void laneSpecificSignal()
 {


    map<string, LaneData> laneData;
    int numLanes;
    cout << "Enter the number of lanes: ";
    cin >> numLanes;

    for (int i = 0; i < numLanes; i++)
        {

        LaneData laneDetails;
        cout << "Enter lane type (e.g., Left Turn, Straight): ";
        cin >> laneDetails.laneType;

        // Get vehicle counts for each lane


        cout << "Enter total vehicle count for " << laneDetails.laneType << ": ";
        cin >> laneDetails.vehicleCount;

        // Simulate vehicle type distribution (or ask for it if needed)

        cout << "Enter truck count for " << laneDetails.laneType << ": ";
        cin >> laneDetails.truckCount;
        cout << "Enter car count for " << laneDetails.laneType << ": ";
        cin >> laneDetails.carCount;
        cout << "Enter bike count for " << laneDetails.laneType << ": ";
        cin >> laneDetails.bikeCount;

        laneData[laneDetails.laneType] = laneDetails;

    }

    // Log the data to a file for record-keeping

     ofstream logFile("lane_signal_log.txt", ios::app);

    logFile << "Lane Specific Signal Log:\n";

    // Adjust signal durations based on the traffic volume in each lane

    for (auto& lane : laneData)
        {

        int duration = lane.second.vehicleCount * 0.5;  // Base duration for the lane

        // Prioritize signal time based on vehicle types

        if (lane.second.truckCount > lane.second.carCount && lane.second.truckCount > lane.second.bikeCount)
            {

            duration += 15;  // Trucks take priority and require more time
            cout << "Lane " << lane.first << ": Priority given to trucks. Extended green light.\n";

        }

        else if (lane.second.carCount > lane.second.bikeCount)
        {

            duration += 10;  // Cars take priority
            cout << "Lane " << lane.first << ": Priority given to cars. Extended green light.\n";


        }

        else

         {
            cout << "Lane " << lane.first << ": Priority given to bikes. Extended green light.\n";

        }

        // Calculate final signal duration based on the number of vehicles

        cout << "Lane " << lane.first << ": Green Light for " << duration << " seconds\n";

        logFile << "Lane " << lane.first << ": Vehicle Count = " << lane.second.vehicleCount
                << ", Truck Count = " << lane.second.truckCount << ", Car Count = " << lane.second.carCount
                << ", Bike Count = " << lane.second.bikeCount << ", Signal Duration = " << duration << " seconds\n";

    }

    // Log end of lane signal data
    logFile << "-----------------------------------\n";
    logFile.close();

}


// 8. Smart Traffic Lights with AI Integration

void smartTrafficSignal()
{


    int vehicleCount;
    string weatherCondition;
    string timeOfDay;

    // Prompt user for vehicle count

    cout << "Enter the vehicle count: ";
    cin >> vehicleCount;

    // Ask for weather condition (could be dynamic or simulated)

    cout << "Enter the current weather (Clear, Rain, Fog): ";
    cin >> weatherCondition;

    // Ask for time of day (morning, afternoon, evening, night)

    cout << "Enter the time of day (morning, afternoon, evening, night): ";
    cin >> timeOfDay;

    // Adjust signal duration based on traffic volume

    int greenSignalDuration = (vehicleCount > 50) ? 60 : 30; // Base duration

    // Adjust signal based on time of day

    if (timeOfDay == "morning" || timeOfDay == "evening")
    {

        greenSignalDuration += 10; // More vehicles expected during these times
        cout << "Peak traffic time detected. Adjusting signal duration.\n";

    }

    // Adjust signal duration based on weather conditions

    if (weatherCondition == "Rain" || weatherCondition == "Fog")

        {

        greenSignalDuration += 15; // Add more time for safety in adverse weather
        cout << "Weather condition " << weatherCondition << " detected. Extending signal time for safety.\n";

        }

    // Vehicle type prioritization (simulated here as a random count)

    int truckCount = rand() % vehicleCount; // Random number of trucks
    int carCount = rand() % vehicleCount;   // Random number of cars
    int bikeCount = vehicleCount - truckCount - carCount;

    // Prioritize signals based on vehicle types (Example: trucks take more time)

    if (truckCount > carCount && truckCount > bikeCount)

        {

        greenSignalDuration += 20; // Trucks need more time to pass
        cout << "Priority given to trucks. Extending green light.\n";

    }

    else if (carCount > bikeCount)
    {

        greenSignalDuration += 10; // Cars need slightly more time
        cout << "Priority given to cars. Extending green light.\n";

    }

    else

     {
        greenSignalDuration += 5;  // Bikes need the least time
        cout << "Priority given to bikes. Extending green light.\n";

    }


    // Log the decisions to a file

    ofstream logFile("traffic_signal_log.txt", ios::app);

    logFile << "--------------------------------------\n";
    logFile << "Vehicle Count: " << vehicleCount << "\n";
    logFile << "Weather: " << weatherCondition << "\n";
    logFile << "Time of Day: " << timeOfDay << "\n";
    logFile << "Truck Count: " << truckCount << ", Car Count: " << carCount << ", Bike Count: " << bikeCount << "\n";
    logFile << "Signal Duration: " << greenSignalDuration << " seconds\n";
    logFile << "--------------------------------------\n";
    logFile.close();

    // Output the result to the user

    cout << "Green Signal Duration: " << greenSignalDuration << " seconds\n";


}

// 9. Night Mode Traffic Signals

void nightModeSignal()

{

    // Get the current system time

    time_t now = time(0);
    tm *ltm = localtime(&now);


    // Check if the current time is between 8 PM (20:00) and 6 AM (06:00)

    bool isNight = (ltm->tm_hour >= 20 || ltm->tm_hour < 6);


    // Logging file to record night mode events

    ofstream logFile("traffic_mode_log.txt", ios::app);

    if (isNight)
        {

        // If it is night, activate night mode

        cout << "Night Mode Activated: Flashing Yellow Light.\n";
        logFile << "Night Mode Activated: Flashing Yellow Light at " << ltm->tm_hour << ":" << ltm->tm_min << "\n";

        // Additional night mode logic based on traffic conditions


        int vehicleCount;

        cout << "Enter the vehicle count for night traffic: ";
        cin >> vehicleCount;

        if (vehicleCount < 10)

        {

            cout << "Low Traffic Volume: Extend flashing yellow light duration.\n";
            logFile << "Low Traffic Volume detected. Extending flashing yellow light duration.\n";

        }

        else

        {

            cout << "Moderate Traffic Volume: Normal flashing yellow duration.\n";
            logFile << "Moderate Traffic Volume detected. Normal flashing yellow light duration.\n";

        }

        // Safety measures for night mode (e.g., extend yellow light for safety)

        cout << "Safety Measure: Extending yellow light for 5 seconds for night driving safety.\n";
        logFile << "Safety Measure: Extended yellow light duration for night driving safety.\n";

    }

    else


    {


// If it's not night time, operate in day mode

        cout << "Day Mode: Normal Traffic Light Operation.\n";
        logFile << "Day Mode: Normal Traffic Light Operation at " << ltm->tm_hour << ":" << ltm->tm_min << "\n";

    }


    // Close the log file after the operation

    logFile.close();

}


// 10. Vehicle Count and Classification

void classifyVehicles()
{

    // Declare variables to store vehicle counts


    int trucks, cars, bikes, emergencyVehicles;
    cout << "Enter the number of trucks: ";
    cin >> trucks;
    cout << "Enter the number of cars: ";
    cin >> cars;
    cout << "Enter the number of bikes: ";
    cin >> bikes;
    cout << "Enter the number of emergency vehicles (if any): ";
    cin >> emergencyVehicles;


    // Output the basic vehicle counts

    cout << "\nVehicle Classification:\n";
    cout << "Trucks: " << trucks << "\nCars: " << cars << "\nBikes: " << bikes << "\nEmergency Vehicles: " << emergencyVehicles << endl;


    // Logic to handle emergency vehicles first

    if (emergencyVehicles > 0)

        {

        cout << "Emergency Vehicle Detected! Immediate priority given to Emergency Vehicle Lane.\n";
        return;  // Exit after giving priority to emergency vehicles

    }

    // Classify lanes based on vehicle counts

    if (trucks > cars && trucks > bikes)
        {

        cout << "Priority given to Truck Lane.\n";

    }

    else if (cars > bikes)

     {

        cout << "Priority given to Car Lane.\n";

    }


    else

     {

        cout << "Priority given to Bike Lane.\n";

   }

    // Lane capacity consideration


    int maxLaneCapacity = 50;  // Arbitrary lane capacity
    if (trucks > maxLaneCapacity)

        {

        cout << "Truck lane exceeds maximum capacity! Consider rerouting some trucks.\n";

    }
    if (cars > maxLaneCapacity)

        {

        cout << "Car lane exceeds maximum capacity! Consider rerouting some cars.\n";

    }
    if (bikes > maxLaneCapacity)
    {

        cout << "Bike lane exceeds maximum capacity! Consider rerouting some bikes.\n";

    }

    // Safety considerations for bike lanes

    if (bikes > 0)

        {

        cout << "Safety measures applied for Bike Lane: Extending green light for bike safety.\n";

    }

    // Traffic Pattern Consideration (Day/Night Time)

    string timeOfDay;
    cout << "Enter the time of day (morning, afternoon, evening, night): ";
    cin >> timeOfDay;

    if (timeOfDay == "morning" || timeOfDay == "evening")

        {


        cout << "Peak traffic hours detected. Adjusting signal timing for higher traffic.\n";

    }

    else

    {

        cout << "Off-peak hours detected. Normal signal timing.\n";

    }

    // Suggest lane changes based on traffic flow

    if (cars > trucks && cars > bikes)
        {

        cout << "Consider opening additional lanes for cars during peak hours.\n";

    }

    else if (trucks > cars && trucks > bikes)
    {

        cout << "Consider creating dedicated truck lanes during peak hours.\n";

    }

    else
    {

        cout << "Consider opening additional lanes for bikes during off-peak hours.\n";

    }

}

// 11. Real-Time Traffic Violation Detection

struct Vehicle
{

    string plateNumber;
    bool violatedSignal;
    string vehicleType; // Added vehicle type
    string violationTime; // Added time of violation
    string intersection; // Added intersection info
    string violationSeverity; // Added violation severity

};


void detectViolations()

{

    int numVehicles;
    cout << "Enter the number of vehicles: ";
    cin >> numVehicles;


    vector<Vehicle> vehicles(numVehicles);

    // Collect data for each vehicle

    for (int i = 0; i < numVehicles; i++)

        {

        cout << "Enter vehicle " << i + 1 << " plate number: ";
        cin >> vehicles[i].plateNumber;


        cout << "Enter vehicle type (Car, Truck, Bike): ";
        cin >> vehicles[i].vehicleType;


        cout << "Enter the intersection where violation occurred: ";
        cin >> vehicles[i].intersection;


        cout << "Enter the violation time (e.g., 10:30 AM): ";
        cin >> vehicles[i].violationTime;


        cout << "Did this vehicle violate the signal? (1 for Yes, 0 for No): ";
        cin >> vehicles[i].violatedSignal;

        // Determine violation severity based on vehicle type or time

        if (vehicles[i].violatedSignal)

            {


            cout << "Was it a severe violation? (1 for Yes, 0 for No): ";
            int severity;
            cin >> severity;
            vehicles[i].violationSeverity = (severity == 1) ? "Severe" : "Minor";

        }

         else
         {

            vehicles[i].violationSeverity = "No Violation";

        }

    }

    // Process violations and provide reports

    cout << "\nViolating Vehicles Report:\n";
    int totalViolations = 0;
    map<string, int> violationCount; // To count violations by vehicle type

    for (auto& v : vehicles)

        {

        if (v.violatedSignal)
            {
            totalViolations++;
            violationCount[v.vehicleType]++;

            cout << "Vehicle " << v.plateNumber << " (Type: " << v.vehicleType << ") violated the signal!\n";
            cout << "Violation Severity: " << v.violationSeverity << "\n";
            cout << "Violation Time: " << v.violationTime << " at " << v.intersection << "\n";
            cout << "--------------------------------------------\n";

        }

    }

    // Display violation statistics

    cout << "\nTotal Violations: " << totalViolations << endl;
    cout << "Violation Breakdown by Vehicle Type:\n";
    for (auto& type : violationCount)

        {
        cout << type.first << ": " << type.second << " violations\n";

    }

    // Optionally log violations to a file

    ofstream logFile("violations_log.txt", ios::app); // Append to log file

    logFile << "Violating Vehicles Report - Total Violations: " << totalViolations << "\n";
    for (auto& v : vehicles)

    {
        if (v.violatedSignal)

            {

            logFile << "Plate Number: " << v.plateNumber << ", Type: " << v.vehicleType
                    << ", Violation Time: " << v.violationTime << ", Intersection: " << v.intersection
                    << ", Severity: " << v.violationSeverity << "\n";

        }

    }


    logFile << "============================================\n";
    logFile.close();

}

// 12. Signal Control During Special Events

void specialEventMode()
{

    bool isEventActive;
    string eventType;
    int eventDuration;
    string eventTime;

    // Ask if there is a special event

    cout << "Is there a special event? (1 for Yes, 0 for No): ";
    cin >> isEventActive;

    if (isEventActive)

        {

        // If there is an event, ask for more details

        cout << "Enter the type of event (e.g., concert, parade, sports): ";
        cin >> eventType;


        cout << "Enter the duration of the green signal extension (in seconds): ";
        cin >> eventDuration;


        cout << "Enter the scheduled time of the event (e.g., 2:00 PM): ";
        cin >> eventTime;


        cout << "Special Event Mode Activated: ";
        cout << "Event Type: " << eventType << "\n";
        cout << "Event Duration: " << eventDuration << " seconds\n";
        cout << "Scheduled Time: " << eventTime << "\n";

        // Customize traffic adjustments based on the event type

        if (eventType == "concert" || eventType == "parade")
            {


            cout << "Priority: Extended green signal on main roads and routes leading to the event.\n";

        }


        else if (eventType == "sports")

         {

            cout << "Priority: Increased green signal duration on access roads to stadiums.\n";

        }

        else

         {


           cout << "Normal Event Priority: Green signals will be extended on major routes.\n";

        }

        // Ask for more specific road adjustments based on event

        string roadType;
        map<string, int> roadAdjustments;
        char moreAdjustments = 'y';


        while (moreAdjustments == 'y' || moreAdjustments == 'Y')
        {


            cout << "Enter the road type to adjust (Main, Secondary, Detour): ";
            cin >> roadType;


            int greenTime;
            cout << "Enter the extended green signal duration for " << roadType << " road: ";
            cin >> greenTime;


            roadAdjustments[roadType] = greenTime;
            cout << "Do you want to add more road adjustments? (y/n): ";
            cin >> moreAdjustments;

        }

        // Display all road adjustments

        cout << "\nRoad Adjustments During Event:\n";

        for (auto& adjustment : roadAdjustments)

            {
            cout << "Road: " << adjustment.first << " - Green Light for " << adjustment.second << " seconds\n";

        }

    }

     else

    {

        cout << "Normal Traffic Mode.\n";

    }


}

// 13. Emergency Signal Override System

void overrideTrafficSignal()
 {


    bool manualOverride;
    cout << "Is manual override active? (1 for Yes, 0 for No): ";
    cin >> manualOverride;


    if (manualOverride)
        {
        // Ask for the type of override

        int overrideType;
        cout << "\nSelect Override Type:\n";
        cout << "1. Flashing Yellow (Caution)\n";
        cout << "2. Flashing Red (Stop)\n";
        cout << "3. All Green (Emergency)\n";
        cout << "4. No Signals (Maintenance)\n";
        cout << "Enter your choice: ";
        cin >> overrideType;

        // Ask for the reason for the override


        string reason;
        cout << "Enter the reason for the manual override (e.g., Emergency, Maintenance, etc.): ";
        cin.ignore();  // To clear the newline from previous input
        getline(cin, reason);

        // Provide override details

        switch (overrideType)

        {

            case 1:
                cout << "Override: Flashing Yellow (Caution) for all signals.\n";

                break;
            case 2:
                cout << "Override: Flashing Red (Stop) for all signals.\n";

                break;
            case 3:
                cout << "Override: All Green signals (Emergency).\n";

                break;
            case 4:
                cout << "Override: No Signals (Maintenance).\n";

                break;
            default:
                cout << "Invalid choice. Reverting to Automatic Signal Control.\n";

                return;

        }

        // Output the reason for override

        cout << "Reason for override: " << reason << endl;

        // Ask for the duration of the override (optional)

        int duration;
        cout << "Enter the duration of the override in minutes (0 for indefinite): ";
        cin >> duration;

        if (duration > 0)
            {


            cout << "Override will last for " << duration << " minutes.\n";

        }

        else
         {

            cout << "Override is set to be indefinite.\n";

        }

        // Ask if the override applies to specific intersections or globally

        char applyToSpecific;
        cout << "Apply override to specific intersections? (y/n): ";
        cin >> applyToSpecific;

        if (applyToSpecific == 'y' || applyToSpecific == 'Y')
            {


            int numIntersections;
            cout << "Enter the number of intersections to override: ";
            cin >> numIntersections;
            for (int i = 0; i < numIntersections; i++)

                {

                string intersection;
                cout << "Enter the name of intersection " << i + 1 << ": ";
                cin >> intersection;
                cout << "Override applied to " << intersection << ".\n";

            }

        }

        else
        {


            cout << "Override applied to all intersections.\n";

        }

        // Notify authorities or log the override event (simulation)

        cout << "\nOverride log: Manual override activated. Reason: " << reason << ". Duration: ";

        if (duration > 0)

            {

            cout << duration << " minutes.";

        }

        else

        {

            cout << "Indefinite duration.";

        }

        cout << "\nOverride applied to all intersections.\n";

    }

    else

    {

        cout << "Automatic Signal Control Active.\n";

    }

}

// 14. Traffic Signal Countdown Timer

void countdownTimer()

{

    int duration;
    cout << "Enter the countdown duration in seconds: ";
    cin >> duration;

    // Using clock() based delay instead of sleep_for

    for (int i = duration; i >= 0; i--)

        {


        cout << "Time Left: " << i << " seconds\n";

        // Delay using clock function to simulate a 1-second delay

        clock_t start_time = clock();


        while (clock() < start_time + CLOCKS_PER_SEC)
            {

            // Busy wait to simulate a delay

        }

    }


    cout << "Signal Changed!\n";
}

// 15. Fuel-Efficient Signal Timing

void fuelEfficientSignal()
{


    int vehicleCount;
    cout << "Enter the vehicle count: ";
    cin >> vehicleCount;

    // Ask for the type of vehicles

    int trucks, cars, bikes;
    cout << "Enter the number of trucks: ";
    cin >> trucks;
    cout << "Enter the number of cars: ";
    cin >> cars;
    cout << "Enter the number of bikes: ";
    cin >> bikes;

    // Calculate total vehicle count

    int totalVehicles = trucks + cars + bikes;

    // Fuel-efficient logic based on total vehicle count and type


    int duration = 30;  // Default duration for lower traffic

    // If vehicle count is more than 50, extend the green light duration

    if (vehicleCount > 50)

        {

        duration = 45;

    }

    // Additional conditions based on vehicle types

    if (trucks > 0 && cars > 0)

        {

        duration += 10;  // Increase signal time if there are both trucks and cars

    }


    // Adjust signal timing based on time of day (peak hours)

    string timeOfDay;
    cout << "Enter time of day (morning, afternoon, evening, night): ";
    cin >> timeOfDay;


    if (timeOfDay == "morning" || timeOfDay == "evening")

        {

        duration += 10;  // Increase green light duration during peak hours
    }

    // Adjust based on weather conditions (e.g., rain, fog)


    string weather;
    cout << "Enter weather condition (clear, rain, fog): ";
    cin >> weather;

    if (weather == "rain" || weather == "fog")

        {
        duration += 5;  // Slightly increase green light duration during bad weather


    }


    // Provide fuel efficiency tips


    if (vehicleCount > 100)

        {


        cout << "High traffic detected! Consider adjusting the signal timing to optimize fuel usage for the entire flow.\n";

    }

    // Display fuel-efficient signal timing


    cout << "Total vehicles: " << totalVehicles << "\n";
    cout << "Green Signal Duration: " << duration << " seconds (Fuel Optimized)\n";


    // Additional notifications for vehicle types

    if (trucks > 0)

        {

        cout << "Trucks detected. Longer green duration recommended for heavy vehicles.\n";



    }

    if (bikes > 0)

        {
        cout << "Bikes detected. Shorter green duration for bike lanes can save fuel.\n";

    }

    // Provide overall fuel optimization suggestions based on conditions

    if (duration > 40)

        {
        cout << "Fuel optimization: Longer signal times are beneficial for traffic flow but may increase fuel consumption in the long term.\n";
    }

    else

    {
        cout << "Fuel optimization: Shorter signal times help reduce idle times and fuel consumption.\n";

    }

}


// 16. Integration with Weather Conditions

void adjustForWeather()

{


    string weather;
    cout << "Enter the current weather (e.g., Rain, Fog, Clear, Snow, Wind): ";
    cin >> weather;

    // Extended Weather Conditions

    if (weather == "Rain" || weather == "Fog")

        {
        cout << "Weather Condition: " << weather << " - Extend signal time for safety.\n";
        cout << "Warning: Increased stopping distance due to poor visibility.\n";


        // You could adjust signal duration based on weather severity, for example:

        int duration = 45;  // Extended green signal time
        cout << "Adjusted Signal Duration: " << duration << " seconds.\n";

    }
    else if (weather == "Snow")

        {
        cout << "Weather Condition: Snow - Extended green signal duration for smoother traffic flow.\n";
        cout << "Warning: Possible slippery roads. Reduce speed and remain cautious.\n";
        int duration = 50;  // Longer green time for smoother flow in snowy conditions
        cout << "Adjusted Signal Duration: " << duration << " seconds.\n";

    }

    else if (weather == "Wind")

        {

        cout << "Weather Condition: Wind - Adjusting traffic flow for wind conditions.\n";
        cout << "Warning: Strong winds may affect vehicle stability. Caution required.\n";
        int duration = 40;  // Moderate signal duration to control traffic efficiently
        cout << "Adjusted Signal Duration: " << duration << " seconds.\n";

    }


    else if (weather == "Clear")

        {
        cout << "Weather Condition: Clear - Normal traffic signal timing.\n";
        int duration = 30;  // Default signal duration
        cout << "Adjusted Signal Duration: " << duration << " seconds.\n";


    }

    else

    {
        cout << "Unknown weather condition. Please enter a valid weather type (e.g., Rain, Fog, Clear, Snow, Wind).\n";

    }


    // Additional user input for actions based on weather

    char actionChoice;
    cout << "Would you like to adjust traffic signals manually based on weather? (y/n): ";
    cin >> actionChoice;

    if (actionChoice == 'y' || actionChoice == 'Y')

        {

        cout << "Manual Adjustment: Apply extended green signal for smooth traffic flow.\n";
        // Implement manual override logic (for example, extending green time)


        int manualDuration;
        cout << "Enter the desired extended green signal duration (in seconds): ";
        cin >> manualDuration;
        cout << "Manual Adjustment: Signal will remain green for " << manualDuration << " seconds.\n";

    }
    else

     {

        cout << "Normal automated traffic control is active.\n";

    }

    // Weather-based safety recommendations


    cout << "Safety Reminder: Always drive cautiously and adjust your speed according to weather conditions.\n";

}

// 17. Pedestrian Smart Button System

void pedestrianCrossing()

 {
    bool buttonPressed;
    cout << "Is the pedestrian button pressed? (1 for Yes, 0 for No): ";
    cin >> buttonPressed;

    if (buttonPressed)

        {
        cout << "Pedestrian Button Pressed: Activating pedestrian crossing signal.\n";

        // Log the current time when the button is pressed


        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "Request received at: " << dt << endl;

        // Determine traffic flow condition


        string trafficFlow;
        cout << "Enter the current traffic flow (Light, Moderate, Heavy): ";
        cin >> trafficFlow;


        int crossingTime = 10;  // Default crossing time


        if (trafficFlow == "Heavy")
            {


            crossingTime = 20;  // Increase pedestrian crossing time if traffic is heavy
            cout << "Heavy traffic detected. Pedestrian crossing time extended to " << crossingTime << " seconds.\n";

        }

        else if (trafficFlow == "Moderate")

        {

            crossingTime = 15;  // Moderate crossing time for moderate traffic
            cout << "Moderate traffic detected. Pedestrian crossing time set to " << crossingTime << " seconds.\n";

        }


        else
        {

            cout << "Light traffic detected. Pedestrian crossing time set to " << crossingTime << " seconds.\n";

        }

        // Simulate pedestrian crossing signal being active for the designated time

        cout << "Pedestrian signal active for " << crossingTime << " seconds.\n";

        // Simulating the time it takes for the pedestrian to cross using clock() method

        for (int i = crossingTime; i > 0; i--)

            {

            cout << "Time remaining for crossing: " << i << " seconds.\n";

            // Using clock() to simulate a 1-second delay


            clock_t start_time = clock();
            while (clock() < start_time + CLOCKS_PER_SEC)

                {

                // Busy-wait to simulate a delay


            }

        }


        cout << "Pedestrian crossing completed.\n";

    }

    else

    {
        cout << "No Pedestrian Request Detected.\n";

    }

    // Check if the pedestrian signal was successfully completed


    char userFeedback;
    cout << "Was the pedestrian crossing safe and completed? (y/n): ";
    cin >> userFeedback;

    if (userFeedback == 'y' || userFeedback == 'Y')

        {
        cout << "Pedestrian crossing was completed successfully.\n";

    }

     else

    {
        cout << "Please ensure pedestrian safety before continuing.\n";

    }

}

// 18. Lane Clearance System During Accidents

void clearAccidentLane()

 {


    bool accidentDetected;
    cout << "Is there an accident? (1 for Yes, 0 for No): ";
    cin >> accidentDetected;

    if (accidentDetected)

        {

        // Collect additional details about the accident


        string accidentLocation, affectedLane;
        cout << "Enter the location of the accident: ";
        cin >> accidentLocation;


        cout << "Which lane is affected (e.g., Left Turn, Right Turn, Straight)? ";
        cin >> affectedLane;

        // Log the accident event with timestamp

        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "Accident detected at " << accidentLocation << " on lane " << affectedLane << ".\n";
        cout << "Incident logged at: " << dt << endl;

        // Simulate extending the green signal for the affected lane


        int extensionTime;
        cout << "Enter how many additional seconds to extend the green signal for lane " << affectedLane << ": ";
        cin >> extensionTime;

        // Check if emergency vehicles are approaching


        bool emergencyVehicleApproaching;
        cout << "Are emergency vehicles approaching? (1 for Yes, 0 for No): ";
        cin >> emergencyVehicleApproaching;

        if (emergencyVehicleApproaching)
        {


            cout << "Emergency vehicles approaching. Giving priority to them.\n";
            extensionTime += 10;  // Extend the green signal for emergency vehicles


        }

        // Log the extended green signal duration

        cout << "Extending green signal for " << affectedLane << " for " << extensionTime << " seconds.\n";

        // Simulating time for the green signal extension without this_thread::sleep_for


        for (int i = extensionTime; i > 0; i--)

            {
            cout << "Time remaining for green light on " << affectedLane << ": " << i << " seconds.\n";

            // Using clock() to simulate 1 second delay


            clock_t start_time = clock();
            while (clock() < start_time + CLOCKS_PER_SEC)

                {

                // Busy-wait to simulate a 1-second delay

            }


        }

        cout << "Green light extended for " << affectedLane << ". Accident clearance in progress.\n";

        // Notify authorities about the accident

        cout << "Sending accident report to authorities...\n";

        // Simulate time taken to send the report using clock()

        clock_t start_time_report = clock();

        while (clock() < start_time_report + 2 * CLOCKS_PER_SEC)

            {

            // Busy-wait to simulate the 2-second delay for sending the report

        }

        cout << "Accident report sent successfully.\n";

        // Simulate clearance of accident

        cout << "Accident cleared. Resuming normal traffic flow.\n";

    }

    else

    {
        cout << "No accident detected. Normal lane operations.\n";

    }

}

// 19. Integration with Smart Vehicles (V2I Communication)

void communicateWithSmartVehicle()
 {


    bool vehicleConnected;
    cout << "Is the smart vehicle connected? (1 for Yes, 0 for No): ";
    cin >> vehicleConnected;

    if (vehicleConnected)
    {

        // Gather more details about the smart vehicle and its connection


        string vehicleType;
        cout << "Enter the type of smart vehicle (e.g., Car, Truck, Bus): ";
        cin >> vehicleType;


        string communicationProtocol;
        cout << "Enter the communication protocol (e.g., V2X, 5G, Bluetooth): ";
        cin >> communicationProtocol;

        cout << "Smart Vehicle (" << vehicleType << ") connected using " << communicationProtocol << " protocol.\n";

        // Simulate the data exchange with the smart vehicle


        string trafficLightStatus = "Green";  // This can be dynamic based on the real-time signal status
        cout << "Sending traffic light status: " << trafficLightStatus << " to smart vehicle.\n";

        // Simulate a response from the smart vehicle

        string vehicleResponse;
        cout << "Smart Vehicle Response: (e.g., 'Proceed', 'Stop', 'Route Update') ";
        cin >> vehicleResponse;

        // Log the communication for future reference

        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "Communication log at: " << dt << endl;
        cout << "Vehicle Response: " << vehicleResponse << endl;


        // Based on response, adjust traffic signal (if needed)

        if (vehicleResponse == "Proceed")

            {

            cout << "Allowing vehicle " << vehicleType << " to pass.\n";

        }

        else if (vehicleResponse == "Stop")

        {
            cout << "Traffic light status: " << trafficLightStatus << " will be kept.\n";

        }

        else if (vehicleResponse == "Route Update")
            {

            cout << "Requesting alternative route for vehicle.\n";

        }

        else

        {
            cout << "Invalid response received. No change to traffic signal.\n";

        }

        // Simulate sending traffic signal status updates


        cout << "Sending traffic signal status updates to connected smart vehicle...\n";

        // Replace sleep with clock() function for delay simulation

        clock_t start_time = clock();
        while (clock() < start_time + 2 * CLOCKS_PER_SEC)

            {
            // Busy-wait to simulate 2-second delay

        }

        cout << "Status updates sent successfully.\n";


    }

    else

     {


        cout << "No Smart Vehicle Detected.\n";

    }

}

// 20. Traffic Signal Health Monitoring System


struct TrafficSignal

{

    string location;
    bool isFunctional;
    string lastMaintenanceDate; // Track last maintenance date
    string malfunctionType; // Type of malfunction (if any)

};


void monitorSignalHealth()

{


    int numSignals;
    cout << "Enter the number of traffic signals to monitor: ";
    cin >> numSignals;


    vector<TrafficSignal> signals(numSignals);

    // Collecting data for multiple traffic signals


    for (int i = 0; i < numSignals; i++)

        {

        cout << "\nEnter details for Signal " << i + 1 << ":\n";
        cout << "Location: ";
        cin >> signals[i].location;
        cout << "Is the signal functional? (1 for Yes, 0 for No): ";
        cin >> signals[i].isFunctional;


        // If the signal is malfunctioning, ask for the malfunction type and last maintenance date

        if (!signals[i].isFunctional)
        {
            cout << "Enter the type of malfunction (e.g., 'Power Outage', 'Signal Flashes'): ";
            cin >> signals[i].malfunctionType;

            // Ask for last maintenance date if the signal is malfunctioning


            cout << "Enter the last maintenance date (format: YYYY-MM-DD): ";
            cin >> signals[i].lastMaintenanceDate;

            // Suggest maintenance based on the last maintenance date


            time_t current_time = time(0);
            struct tm *now = localtime(&current_time);
            int currentYear = now->tm_year + 1900; // Current year


            int lastMaintenanceYear = stoi(signals[i].lastMaintenanceDate.substr(0, 4)); // Extract the year from the date


            if (currentYear - lastMaintenanceYear >= 1)

                {

                cout << "Maintenance due for Signal at " << signals[i].location << "!\n";
            }

            else

             {
                cout << "Signal at " << signals[i].location << " was recently maintained.\n";

            }

        }

    }

    // Displaying health status for all signals

    cout << "\n--- Traffic Signal Health Report ---\n";

    for (const auto& signal : signals)

     {
        if (signal.isFunctional)

            {
            cout << "Signal at " << signal.location << " is functional.\n";

        }

         else

        {
            cout << "Signal at " << signal.location << " is malfunctioning! Type: " << signal.malfunctionType
                 << ", Last Maintenance Date: " << signal.lastMaintenanceDate << endl;

        }

    }

}


void reducingTravelCosts()

{
    int choice;

    do

        {
        cout << "\nSelect a function to execute:\n";
        cout << "1. Dynamic Signal Timing\n";
        cout << "2. Pedestrian Signal Integration\n";
        cout << "3. Emergency Vehicle Priority\n";
        cout << "4. Synchronize Traffic Lights\n";
        cout << "5. Detect Malfunctioning Traffic Lights\n";
        cout << "6. Predict Traffic Density\n";
        cout << "7. Lane-Specific Signal Control\n";
        cout << "8. Smart Traffic Signal\n";
        cout << "9. Night Mode Traffic Signals\n";
        cout << "10. Vehicle Count and Classification\n";
        cout << "11. Real-Time Traffic Violation Detection\n";
        cout << "12. Special Event Mode\n";
        cout << "13. Emergency Signal Override\n";
        cout << "14. Traffic Signal Countdown Timer\n";
        cout << "15. Fuel-Efficient Signal Timing\n";
        cout << "16. Weather-Adjusted Signal Timing\n";
        cout << "17. Pedestrian Smart Button System\n";
        cout << "18. Lane Clearance During Accidents\n";
        cout << "19. Integration with Smart Vehicles\n";
        cout << "20. Traffic Signal Health Monitoring\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)

        {
            case 1:
                dynamicSignalTiming();

                break;
            case 2:
                pedestrianSignal();

                break;
            case 3:
                emergencyVehicleSignal();

                break;
            case 4:
                srand(time(0));  // Seed for random traffic generation
                synchronizeTrafficLights();

                break;
            case 5:
                srand(time(0));
                detectMalfunction();

                break;
            case 6:
                srand(time(0));
                predictTrafficDensity();

                break;
            case 7:
                laneSpecificSignal();

                break;
            case 8:
                srand(time(0));
                smartTrafficSignal();

                break;
            case 9:
                nightModeSignal();
                break;
            case 10:
                classifyVehicles();
                break;
            case 11:
                detectViolations();

                break;
            case 12:
                specialEventMode();
                break;
            case 13:
                overrideTrafficSignal();

                break;
            case 14:
                countdownTimer();
                break;
            case 15:
                fuelEfficientSignal();
                break;
            case 16:
                adjustForWeather();

                break;
            case 17:
                pedestrianCrossing();

                break;
            case 18:
                clearAccidentLane();

                break;
            case 19:
                communicateWithSmartVehicle();

                break;
            case 20:
                monitorSignalHealth();

                break;
            case 0:
                cout << "Exiting...\n";

                break;
            default:
                cout << "Invalid choice! Please select a valid option.\n";

        }

    }

     while (choice != 0);

    //return 0;

}

bool canAffordWeight(int maxCapacity, int currentWeight, int totalWeight)

{
    return currentWeight + totalWeight <= maxCapacity;

}

// Function to add a passenger to the vehicle

bool addPassenger(int& currentWeight, int maxCapacity, vector<int>& passengerWeights, int weight)

 {
    if (currentWeight + weight <= maxCapacity)

        {
        passengerWeights.push_back(weight);
        currentWeight += weight;
        cout << "Passenger with weight " << weight << " added successfully.\n";

        return true;
    }

     else

    {
        cout << "Cannot add passenger. Vehicle capacity exceeded.\n";
        return false;


    }

}

// Function to remove a passenger from the vehicle

bool removePassenger(int& currentWeight, vector<int>& passengerWeights, int weight)

{
    for (auto it = passengerWeights.begin(); it != passengerWeights.end(); ++it)

        {
        if (*it == weight)

        {
            passengerWeights.erase(it);
            currentWeight -= weight;
            cout << "Passenger with weight " << weight << " removed successfully.\n";
            return true;

        }


    }
    cout << "Passenger with weight " << weight << " not found.\n";


    return false;
}

// Function to display the current status of the vehicle

void displayStatus(string vehicleName, int currentWeight, int maxCapacity, vector<int>& passengerWeights)

{
    cout << "Vehicle Name: " << vehicleName << "\n";
    cout << "Current weight of passengers: " << currentWeight << " kg\n";
    cout << "Remaining capacity: " << (maxCapacity - currentWeight) << " kg\n";
    cout << "Total passengers: " << passengerWeights.size() << "\n";
}

// Function to display the total number of passengers
void displayTotalPassengers(vector<int>& passengerWeights)

 {
    cout << "Total passengers: " << passengerWeights.size() << "\n";
}

// Function to display the total weight of passengers

void displayTotalWeight(int currentWeight)

{
    cout << "Total weight of passengers: " << currentWeight << " kg\n";
}

// Function to clear all passengers from the vehicle

void clearAllPassengers(int& currentWeight, vector<int>& passengerWeights)
{
    passengerWeights.clear();
    currentWeight = 0;
    cout << "All passengers removed.\n";

}

// Function to display the remaining capacity of the vehicle

void displayRemainingCapacity(int maxCapacity, int currentWeight)
 {
    cout << "Remaining capacity: " << (maxCapacity - currentWeight) << " kg\n";

}

// Function to display the list of all passengers' weights

void displayPassengerList(vector<int>& passengerWeights)

{
    cout << "Passenger List:\n";
    for (int weight : passengerWeights)
        {
        cout << weight << " kg\n";

    }

}

// Function to manage the vehicle (adding/removing passengers, checking status)
void manageVehicle()
{

    string vehicleName;
    int maxCapacity;
    int currentWeight = 0;  // Initially, no passengers
    vector<int> passengerWeights;

    // Get vehicle details from the user

    cout << "Enter vehicle name: ";
    cin >> vehicleName;
    cout << "Enter maximum weight capacity of the vehicle: ";
    cin >> maxCapacity;

    // Menu for user to interact with the vehicle system
    while (true)
        {
        int choice;

        cout << "\nMENU:\n";
        cout << "1. Add Passenger\n";
        cout << "2. Remove Passenger\n";
        cout << "3. Check Vehicle Status\n";
        cout << "4. Display Total Passengers\n";
        cout << "5. Check Total Weight\n";
        cout << "6. Clear All Passengers\n";
        cout << "7. Check Remaining Capacity\n";
        cout << "8. Display Passenger List\n";
        cout << "9. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                 {
                int weight;
                cout << "Enter passenger weight: ";
                cin >> weight;
                addPassenger(currentWeight, maxCapacity, passengerWeights, weight);
                break;

            }
            case 2:
                {
                int weight;
                cout << "Enter passenger weight to remove: ";
                cin >> weight;
                removePassenger(currentWeight, passengerWeights, weight);

                break;

            }
            case 3:
                displayStatus(vehicleName, currentWeight, maxCapacity, passengerWeights);

                break;
            case 4:
                displayTotalPassengers(passengerWeights);

                break;
            case 5:
                displayTotalWeight(currentWeight);

                break;
            case 6:
                clearAllPassengers(currentWeight, passengerWeights);

                break;
            case 7:
                displayRemainingCapacity(maxCapacity, currentWeight);

                break;
            case 8:
                displayPassengerList(passengerWeights);

                break;
            case 9:
                cout << "Exiting...\n";

                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    }
}
void managingPassengerLoad()

 {
     manageVehicle();
    //return 0;
}

// Main function
int main()
 {
    int choice;

    // Display the menu

    cout << "Select an option:\n";
    cout << "1) Optimal Route Planning\n";
    cout << "2) weather prediction based on traffic\n";
    cout << "3) traffic management\n";
    cout << "4) Managing Passenger Load\n";
    cout << "Enter your choice: ";
    cin >> choice;

    // Process the choice using switch-case

    switch (choice)
    {
        case 1:
            optimalRoutePlanning();

            break;
        case 2:
            increasingNetworkCoverage();

            break;
        case 3:
            reducingTravelCosts();

            break;
        case 4:
            managingPassengerLoad();

            break;
        default:
            cout << "Invalid choice. Please select a valid option (1-4).\n";

            break;
    }

    return 0;
}
