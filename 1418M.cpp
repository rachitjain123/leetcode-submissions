class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string>foodItem;
        set<int> tableNumbers;
        vector<vector<string> >allTableOrders;
        vector<string>header;
        map<pair<string,string>, int> mappingFoodtoTable;
        for(int i=0;i<orders.size();i++)
        {
            string fooditem = orders[i][2];
            string tableno = orders[i][1];
            foodItem.insert(fooditem);
            tableNumbers.insert(stoi(tableno));
            mappingFoodtoTable[{fooditem, tableno}] += 1;
        }
        header.push_back("Table");
        for(auto item:foodItem)
            header.push_back(item);
        allTableOrders.push_back(header);
        
        for(auto tableNum : tableNumbers)
        {
            vector<string> tableOrder;
            string tableno = to_string(tableNum);
            tableOrder.push_back(tableno);
            
            for(int i=1;i<header.size();i++)
            {
                string fooditem=header[i];
                if(mappingFoodtoTable.find({fooditem, tableno}) != mappingFoodtoTable.end())
                    tableOrder.push_back(to_string(mappingFoodtoTable[{fooditem, tableno}]));
                else
                    tableOrder.push_back("0");
            }
            
            allTableOrders.push_back(tableOrder);
        }
        
        return allTableOrders;
    }
};