void printPascal(int n){
    int arr[n][n];
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j or j == 0)
                arr[i][j] = 1;
            
            else
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            
            cout<<arr[i][j]<< " ";
                
        }
        cout<<endl;
    }
}

------------------------------------------------------------------------
  
  void printPascal(int n){
    for(int i = 0 ; i < n ; i++){
        int c = 1;
        cout<<c<<" ";
        
        for(int j = 1 ; j <= i ; j++){
            c = c*(i-j+1)/j;
            cout<<c<<" ";
        }
        cout<<endl;
    }
}
  
  
