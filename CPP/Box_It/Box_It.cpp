#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box{
    private:
        int l;
        int b;
        int h;
    public:
        Box()
        {
            l = h = b = 0;
        }
        Box(int x, int y, int z)
        {
            l = x;
            b = y;
            h = z;
        }
        Box(Box &a)
        {
            this->l = a.l;
            this->h = a.h;
            this->b = a.b;
        }
        
        int getLength()
        {
            return l;
        }
        
        int getBreadth()
        {
            return b;
        }
        
        int getHeight()
        {
            return h;
        }
        
        long long CalculateVolume()
        {
            return (long long)l * b * h;
        }
        
        bool operator<(Box& a)
        {
            if(this->l < a.l)
            {
                return true;
            }
            else if(this->l == a.l) 
            {
                if(this->b < a.b)
                {
                    return true;    
                }
                else if(this->b == a.b)
                {
                    if(this->h < a.h)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    } 
                }
                else
                {
                    return false;
                }
                
            }
            else
            {
                return false;
            }
            
        }
        
        friend ostream& operator<<(ostream& out, Box& B)
        {
            std::cout << B.l << " " << B.b << " " << B.h;
            
            return out;
        }
};



void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}


/*
Box b1; // Should set b1.l = b1.b = b1.h = 0;
Box b2(2, 3, 4); // Should set b1.l = 2, b1.b = 3, b1.h = 4;
b2.getLength();	// Should return 2
b2.getBreadth(); // Should return 3
b2.getheight();	// Should return 4
b2.CalculateVolume(); // Should return 24
bool x = (b1 < b2);	// Should return true based on the conditions given
cout<<b2; // Should print 2 3 4 in order.
*/
