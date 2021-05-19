// We maintain a queue whose first element gets pushed into the result vector. 
// The two strings s1 and s2 contain the next two numbers' binary representation which can be obtained by appending 0 and 1 to the current two respectively

vector<string> generate(int N)
{
	
	queue<string> q;
	vector<string> v;
	
	q.push("1");
	
	while(N--){
	    string s1 = q.front();
	    q.pop();
	    v.push_back(s1);
	    
	    string s2 = s1;
	    
	    q.push(s1.append("0"));
	    q.push(s2.append("1"));
	}
	
	return v;
}
