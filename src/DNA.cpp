#include "DNA.h"
#include"RNA.h"
#include<cstring>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
class RNA;
DNA::DNA()//default
{
    seq=new char[100];
}
DNA::DNA(char*sequence,DNA_Type atype)//parameterized constructor
{
    seq=new char[strlen(sequence)+1];
    strcpy(seq,sequence);
    type=atype;
}
void DNA::setseq(char*sequence)// setting sequence
{
    seq=new char[strlen(sequence)+1];
    strcpy(seq,sequence);
}
char* DNA::getseq() //getting sequence
{
    return seq;
}
DNA::DNA(const DNA& rhs)//copy constructor.
{
    type=rhs.type;
    int Size;
    Size=(strlen(seq))+1;
    seq=new char[Size];
    for(int i=0; i<Size; i++)
        seq[i]=rhs.seq[i];
}
 const DNA DNA:: operator=(const DNA &rhs)
   {
       delete []seq;
       type=rhs.type;
      int Size;
      Size=(strlen(seq))+1;
      seq=new char[Size];
      for(int i=0; i<Size; i++)
        seq[i]=rhs.seq[i];
        return *this;
      }
void DNA:: print()
{
    cout<<seq<<endl;
}

istream&operator >> (istream&in, DNA&rhs)
{
    cout<<"start number : "<<endl;
    in>>rhs.startchar;
    cout<<"End number : "<<endl;
    in>>rhs.endchar;
    return in;
}
void DNA::loadsequencefromfile(char*filename)
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
void DNA::savesequencetofile(char*filename)
{
    ofstream outfile;
    outfile.open(filename);
    if(outfile)
        outfile<<seq;
    else
        cout<<"error opening file ";
    outfile.close();
}
void DNA:: buildcomplementarystrand()
{
    int s=strlen(seq);
    int j=0;
    DNA*complementary_strand= new DNA;
    complementary_strand->seq=new char[s];
    for(int i=s-1; i>=0; i--)
    {
        complementary_strand->seq[j++]=seq[i];//ele hya *comp_st.seq;
    }
    for(int i=0; i<s; i++)
    {
        if(complementary_strand->seq[i]=='A')
            complementary_strand->seq[i]='T';
        else if(complementary_strand->seq[i]=='T')
            complementary_strand->seq[i]='A';
        else if(complementary_strand->seq[i]=='C')
            complementary_strand->seq[i]='G';
        else if(complementary_strand->seq[i]=='G')
            complementary_strand->seq[i]='C';

    }
    cout<<complementary_strand->seq<<endl;
    for(int i=0; i<s; i++)
        seq[i]=complementary_strand->seq[i];


}
RNA DNA::converttoRNA ()
{
    RNA r;
    int s=strlen(seq);
    for(int i=0; i<s; i++)
    {
        if(seq[i]=='T')
            seq[i]='U';
    }
    r.setseq(seq);
    return r;
}

bool DNA :: operator==(DNA &rhs)
{
    int x ;
    x =strlen(seq)+1 ;


    for(int i =0 ; i<x ; i++)
    {
        if(seq[i]=!rhs.seq[i])
            return false ;
    }
    return true ;
}
bool DNA :: operator!=(DNA &rhs)
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
DNA DNA ::operator+( DNA &rhs)
{
    DNA sum ;
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
bool  DNA :: Invalid_sequence(char *s)
{
    int len=strlen(s)+1;
    for(int i =0;i<len ; i++)
    {
       if(s[i]!='A'&&s[i]!='C'&&s[i]!='G'&&s[i]!='T')
            return false ;

    }



}
DNA::~DNA()
{
    delete []seq;
}

