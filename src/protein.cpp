#include "protein.h"
//
protein::protein()
{
    seq=new char[100];
}
void protein::setseq(char*sequence)
{
     seq=new char[strlen(sequence)+1];
    strcpy(seq,sequence);
}
char* protein::getseq()
{
    return seq;
}
 void protein:: print()
{
    cout<<seq<<endl;
}
void protein:: loadsequencefromfile(char*filename)
{
     int i=0;
    int count=0;
    char c;
    bool done=false;
    ifstream infile;
    infile.open(filename);
    if(infile)
    {
        while((infile>>c) && (!done))
        {
            count++;
            if(count>=startchar&&count<=endchar)
            {
                seq[i]=c;
                i++;
                if(count==endchar)
                    done=true;
            }

        }
        cout<<seq<<endl;
    }
        else
            cout<<"error opening file";
            infile.close();
}

bool protein :: operator==(protein &rhs)
{
    int x ;
    x =strlen(seq)+1 ;
    for(int i =0 ; i<x ; i++)
    {
        if((seq[i])=!(rhs.seq[i]))
           return false ;
   }
    return true ;
}
bool protein :: operator!=(protein &rhs)
{

    int x ;
    x =strlen(seq)+1 ;

    for(int i =0 ; i<x ; i++)
    {
        if(seq[i]=!rhs.seq[i])
            return true ;
    }
    return false ;
}

protein protein ::operator+( protein &rhs)
{
    protein sum ;
    int s = strlen(seq);
    int s1 = strlen(rhs.seq);
    for (int i = 0;i<s;i++)
    {
        sum.seq[i]=seq[i];
            }
    for(int i = s ; i<s1 ; i++)
    {
        sum.seq[i]=rhs.seq[i];
    }
    return sum ;
}
void protein:: savesequencetofile(char*filename)
{

    ofstream outfile;
    outfile.open(filename);
    if(outfile)
        outfile<<seq;
    else
        cout<<"error opening file ";
         outfile.close();
}
protein::~protein()
{
    //dtor
}
