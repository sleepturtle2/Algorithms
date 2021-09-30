int tour(vector<petrolPump>&p, int n)
{
    int start = 0; 
    int requiredFuel = 0; 
    int extraFuel = 0; 
    for(int i=0; i<n;i++)
    {
        extraFuel += (p[i].petrol - p[i].distance); 
        if(extraFuel < 0)
        {
            start = i + 1; 
            requiredFuel += extraFuel; 
            extraFuel = 0; 
        }
    }
    if(requiredFuel + extraFuel >=0 )
    return start; 

    return -1; 
}