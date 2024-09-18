# Jak Dojade

## Project Description

This project is a C++ implementation of a pathfinding problem on a rectangular grid map. Each map field can be either empty (impassable), a road (passable in both directions), or a city. Cities are defined by names spread over multiple grid cells, and moving between adjacent grid cells takes one minute. Certain cities are connected by one-way air routes, which can be used for faster travel.

The program reads a map, city connections, and a series of travel queries. For each query, it computes the shortest travel time between two cities, optionally providing the full travel route. The challenge was to solve the problem efficiently while adhering to specific constraints, such as avoiding the use of standard C++ libraries like `std::string` and smart pointers. Instead, custom data structures and memory management techniques were implemented.

## Input Format

- The first line contains the dimensions of the map: width `w` and height `h`.
- The next `h` lines represent the map using the following symbols:
    - `.`: Empty (impassable) field
    - `#`: Road (passable in both directions)
    - `*`: City
    - Letters or digits representing part of a city's name
- The next line contains a single integer `k` representing the number of one-way air connections between cities.
- The following `k` lines contain the description of each connection in the format: `source destination time`.
- The next line contains a single integer `q` representing the number of queries.
- Each of the next `q` lines is a query of the format: `source destination type`.

### Query types:
- Type `0`: The query is only for the travel time.
- Type `1`: The query also requests the full travel route.

## Output Format

For each query, the program outputs the shortest travel time between the cities. If the query type is `1`, the route is also output, with all intermediate cities listed in order.

## Example

**Input:**
20 20
.........GDANSK.....
........*...........
........#...........
........#...........
*##################.
#SZCZECIN.........#.
#.................#.
##................#.
.############*#####.
.#...WARSZAWA.......
.#..................
.#############......
.#...........#......
.#..WROCLAW.##......
.#..*.......*.......
.####.......#KIELCE.
......*##.#########.
.OPOLE..#.*.......#.
........#.KRAKOW..#.
........###########.
0
3
KIELCE KRAKOW 0
KRAKOW GDANSK 0
KRAKOW GDANSK 1

**Output:**
5
40
40 KIELCE SZCZECIN

## Skills Developed

- **Object-Oriented Programming**: Designed the solution using classes and references, implementing custom data structures for string manipulation, memory management, and map traversal.
- **Algorithm Design**: Applied graph traversal algorithms (Dijkstra’s shortest path)
- **Custom Data Structures**: Implemented custom string classes and data structures instead of using standard libraries, ensuring efficient memory usage and management.
- **Memory Management**: Manually managed memory with custom pointers, ensuring proper memory deallocation.



