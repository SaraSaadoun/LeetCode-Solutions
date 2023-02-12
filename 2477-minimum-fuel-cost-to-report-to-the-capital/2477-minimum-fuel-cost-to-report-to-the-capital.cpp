class Solution {
public:
    int seats_no;
    long long fuel_liters_no = 0;
    vector<vector<int>> adj;
    /*
    at any node(city) we get all the no of its children + 1 
                             (representative of them) + (representative of curr city)
    then, calculate no of liters to reach this city(node)
    since each car moves from one city to another by 1 liter
    then no of liters to reach this city = no of cars
    x = no of cars = ceil(all representatives / seats) 
    then to reach this node => we need x liters
    accummulate these liters till u reach the node 0 (beccause the current cars still need to move to reach node 0 not just the current one)

    */
    long long dfs(int node, int parent){   
        //get the total no of representatives till this city (node)
        int rep = 1;
        for(auto child: adj[node]){
            if(child != parent){
                rep += dfs(child, node);
            }
        }
        //if u reached node 0 , u r already in the capital so return ans
        //else u are at some node so, calc no of liters to reach its parent
        if(node != 0)
            fuel_liters_no += (rep + seats_no -1) / seats_no;
        
        
        return rep;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        seats_no = seats;
        adj = vector<vector<int>> (100009);

        for(auto road: roads){
            int city_a = road[0];
            int city_b = road[1];
            adj[city_a].push_back(city_b);
            adj[city_b].push_back(city_a);
        }
        dfs(0, -1);
        return fuel_liters_no;
    }
};