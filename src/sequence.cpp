#include "sequence.h"
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
sequence::sequence( sequence& rhs)//copy constructor.
{
    int Size;
    Size=(strlen(seq))+1;
    seq=new char[Size];
    for(int i=0; i<Size; i++)
        seq[i]=rhs.seq[i];
}
void sequence::setseq(char*sequence)// setting sequence
{
    seq=new char[strlen(sequence)+1];
    strcpy(seq,sequence);
}
char* sequence::getseq() //getting sequence
{
    return seq;
}
char* Align(sequence* s1,sequence *s2)
{
    int L1=strlen(s1->seq);
    int L2=strlen(s2->seq);
//    int index=0;
//    sequence* s3=new sequence;
//    s3->seq=new char[L2];//hya msh far2a l1 aw l2
    char* seq=new char[L2];
    int index=0;
    for(int i=0;i<L1;i++)
    {
        for(int j=0;j<L2;j++)
        {
            if(s1->seq[i]==s2->seq[j])
            {
                seq[i]=s2->seq[j];


            }
        }
    }
    for(int i =0;i<L1;i++)
    {
        if(seq[i]==seq[i+1])
            seq[i+1]=0;
    }


    return seq;
}
sequence::~sequence()
{
    delete []seq;
}
