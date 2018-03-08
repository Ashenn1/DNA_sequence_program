#include "RNA.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include"DNA.h"
#include"protein.h"
#include<string>
using namespace std;
RNA::RNA()
{
     seq=new char[100];
}
 RNA::RNA(char*sequence,RNA_Type atype)
 {
     seq=new char[strlen(sequence)+1];
     strcpy(seq,sequence);
     type=atype;
 }
 void RNA::setseq(char*sequence)
{
     seq=new char[strlen(sequence)+1];
    strcpy(seq,sequence);
}
char* RNA::getseq()
{
    return seq;
}
  void RNA::print()
  {
      cout<<seq;
  }
//RNA::RNA(const RNA& rhs)
//{
//    type=rhs.type;
//    int Size;
//    Size=(strlen(seq))+1;
//    seq=new char[Size];
//    for(int i=0;i<Size;i++)
//        seq[i]=rhs.seq[i];
//}
istream&operator >> (istream&in, RNA&rhs)
{
    cout<<"start number : "<<endl;
    in>>rhs.startchar;
    cout<<"End number : "<<endl;
    in>>rhs.endchar;
    return in;
}
DNA RNA::ConvertToDNA()
{
    DNA d;
    int s=strlen(seq);
    int j=0;
    char*dummy=new char[s];
    for(int i=0;i<s;i++)
    {
      if(seq[i]=='U')
        seq[i]='T';
    }
     for(int i=s-1;i>=0;i--)
    {
         dummy[j++]=seq[i];
    }
    d.setseq(dummy);
    return d;
}
 void RNA:: loadsequencefromfile(char*filename)
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
}
 protein RNA:: ConvertToProtein(const CodonsTable& table)//const was giving me an error here so i had to remove it.
 {
     codon c;
     protein p;
     int x=0;
     int count=0;
     char*val=new char[3];
     char*newpseq=new char[strlen(seq)]; //3shan a7ot feh el sequence el gdeda bt3t el protein
//    table.loadcodonsfromfile("RNA_codon_table.txt");
    for(int i=0;i<strlen(seq);i++)
    {
        val[count]=seq[i];//val[count]:3shan el value tb2a daymn btbd2 mn el zero till it reaches 3.
        count++;
        if(count==3)
        {
            c=table.getaminoacid(val);
            newpseq[x]=c.AminoAcid;
            x++;
            count=0;
            val=new char[3];
        }
    }
    p.setseq(newpseq);
    return p;
 }

 void RNA::savesequencetofile(char*filename)
{
    ofstream outfile;
    outfile.open(filename);
    if(outfile)
        outfile<<seq;
    else
        cout<<"error opening file ";
}
////{
////
////}

bool RNA :: operator==(RNA &rhs)
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
bool RNA :: operator!=(RNA &rhs)
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

RNA RNA ::operator+( RNA &rhs)
{
    RNA sum ;
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
RNA::~RNA()
{
  delete []seq;
}



