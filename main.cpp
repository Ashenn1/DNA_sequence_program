#include <iostream>
#include<iomanip>
#include<fstream>
#include"sequence.h"
#include"DNA.h"
#include"RNA.h"
#include"CodonsTable.h"
using namespace std;

int main()
{
    char*seq1=new char[100];
    char*seq2=new char[100];
    char*filename=new char[20];
    protein p;
    DNA d;
    RNA R;
    CodonsTable C;
    int typ;
    DNA_Type t;
    RNA_Type r;
    Protein_Type pr;
    char c;
    char c2;
    int choice ;
    bool statment;
    cout<<"Enter D for DNA or R for RNA or P for protein or A for Alignment of 2 sequences : "<<endl;
    cin>>c;

    sequence*pseq;

    switch(c)
    {
    case'D':
        pseq=new DNA;
        cout<<"Enter your sequence and it's type (0,1,2,3) :"<<endl ;
        //cin>>seq1>>typ;
         try
         {
             cin>>seq1>>typ;
             statment=d.Invalid_sequence(seq1);
//             for(int i=0 ;i<strlen(seq1);i++)
//                 if(seq1[i]!='A'&&seq1[i]!='C'&&seq1[i]!='G'&&seq1[i]!='T')
//                 cout<< "Invalid Input !"<<endl ;
         }
         catch(bool statment)
         {
             cout<<"Error !"<<endl;
         }
        ((DNA*)pseq)->setseq(seq1);
        cout<<"chose 1 to convert to RNA or 2 to Protein :"<<endl;
        cin>>choice ;
        if (choice ==1)
        {
            R=((DNA*)pseq)->converttoRNA();
            cout<<"The sequence converted to RNA : "<<endl;
            cout<<R.getseq();
            cout<<"Enter the name of the file you'd want to save your sequence in :"<<endl;
            cin>>filename;
            try
            {
            pseq->savesequencetofile(filename);//overridden in the DNA function
            }
            catch(...)
            {
                cout<<"File not found"<<endl;
            }
            cout<<"your sequence is saved successfully ! "<<endl;

        }
        else if(choice==2)
        {
            R=((DNA*)pseq)->converttoRNA();
            try
            {
           C.loadcodonsfromfile("RNA_codon_table.txt");//overridden in the DNA function
            }
            catch(...)
            {
                cout<<"File not found"<<endl;
            }


            p=((RNA*)pseq)->ConvertToProtein(C);
            cout<<"The converted protein sequence is :"<<endl;
            cout<<p.getseq();
        }

    case 'R':
        pseq=new RNA;
        cout<<"Enter your sequence and it's type(0,1,2,3) :"<<endl ;

         try
         {
             cin>>seq1>>typ;
             for(int i=0 ;i<strlen(seq1);i++)
                 if(seq1[i]!='A'&&seq1[i]!='C'&&seq1[i]!='G'&&seq1[i]!='T')
                 cout<< "Invalid Input !"<<endl ;
         }
         catch(...)
         {
             cout<<"Error !"<<endl;
         }

        ((RNA*)pseq)->setseq(seq1);
        cout<<"chose 1 to convert to DNA or 2 to Protein :"<<endl;
        cin>>choice ;
        if (choice ==1)
        {
            d=((RNA*)pseq)-> ConvertToDNA();
            cout<<"The sequence converted to RNA : "<<endl;
            cout<<d.getseq()<<endl;
            cout<<"Enter the name of the file you'd want to save your sequence in :"<<endl;
            cin>>filename;
            try
            {
            pseq->savesequencetofile(filename);//overridden in the DNA function
            }
            catch(...)
            {
                cout<<"File not found"<<endl;
            }

            //pseq->savesequencetofile(filename);//overridden in the DNA function
            cout<<"your sequence is saved successfully ! "<<endl;
        }
        else if(choice==2)
        {
            C.loadcodonsfromfile("RNA_codon_table.txt");
            p=((RNA*)pseq)->ConvertToProtein(C);
            cout<<"The converted protein sequence is :"<<endl;
            cout<<p.getseq()<<endl;
            cout<<"Enter the name of the file you'd want to save your sequence in :"<<endl;
            cin>>filename;
            try
            {
            pseq->savesequencetofile(filename);//overridden in the DNA function
            }
            catch(...)
            {
                cout<<"File not found"<<endl;
            }

            //pseq->savesequencetofile(filename);
        }

      case 'A':
           sequence*pseq=new DNA;
      sequence*s2=new RNA;
      char*s3=new char[100];
     cout<<"enter 2 sequences :"<<endl;
     cin>>seq1>>seq2;
      try
         {
             for(int i=0 ;i<strlen(seq1);i++)
                 if(seq1[i]!='A'&&seq1[i]!='C'&&seq1[i]!='G'&&seq1[i]!='T')
                 cout<< "Invalid Input !"<<endl ;
     }
         catch(...)
         {
             cout<<"Error !"<<endl;
         }
        try
         {
             for(int i=0 ;i<strlen(seq2);i++)
                 if(seq2[i]!='A'&&seq2[i]!='C'&&seq2[i]!='G'&&seq2[i]!='T')
                 cout<< "Invalid Input !"<<endl ;
         }
         catch(...)
         {
             cout<<"Error !"<<endl;
         }

     pseq->setseq(seq1);//by3ady 3la el setseq bt3t el DNA l2n bt3t el base class virtual
     s2->setseq(seq2);
     s3=Align(pseq,s2);
     cout<<"their alignment is :"<<endl;
     cout<<s3;



    }




    return 0;
}
