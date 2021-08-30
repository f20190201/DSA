// result of n - 2 helps in finding result of n
// If n != length, we can have numbers starting and ending with 0 in the vector
// Special case for n == 2 and length == 2

vector<string>numbers(int n , int length){
    if(n == 0)
        return {};
    if(n == 1)
        return {"0" , "1" , "8"};
    
    if(n == 2 && length == 2)
        return {"11" , "69" , "88" , "96"};
    
    else if(n == 2 && length != 2)
        return {"00" , "11" , "69" , "88" , "96"};
    
    vector<string> middles = numbers(n - 2 , length) , res;

    if(n != length){
        for(int i = 0 ; i < middles.size() ; i++){
            string s = "0";
            s += middles[i];
            s += "0";
            res.push_back(s);    
        }
    }

    //for 11
    for(int i = 0 ; i < middles.size() ; i++){
        
        string s = "1";
        s += middles[i];
        s += "1";
        res.push_back(s);
    }
    
    //for 69
    for(int i = 0 ; i < middles.size() ; i++){

        string s = "6";
        s += middles[i];
        s += "9";
        res.push_back(s);
    }

    //for 88
    for(int i = 0 ; i < middles.size() ; i++){

        string s = "8";
        s += middles[i];
        s += "8";
        res.push_back(s);
    }

    //for 96
    for(int i = 0 ; i < middles.size() ; i++){
       
        string s = "9";
        s += middles[i];
        s += "6";
        res.push_back(s);
    }

    return res;
        
}

vector<string> solve(int n) {
    return numbers(n , n);
}
