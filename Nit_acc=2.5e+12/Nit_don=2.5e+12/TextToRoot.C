#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdio>




using namespace std;

TF1 *f1, *f2;
double finter(double *x, double*par) {
   return TMath::Abs(f1->EvalPar(x,par) - f2->EvalPar(x,par));
}


int sort_string_vector(vector<string> &stringVec)
{
 for (vector<string>::size_type i = 0; i != stringVec.size(); ++i)
    {
    // Sorting the string vector
    sort(stringVec.begin(), stringVec.end());
    // Ranged Based loops. This requires a C++11 Compiler also
    // If you don't have a C++11 Compiler you can use a standard
    // for loop to print your vector.

    cout << stringVec[i] << endl;

}
 return 0;
}
void Convert_TestDataFile_To_RootTree(TString TextDataName, TString RootDataName)
{
   TFile *f = new TFile(RootDataName,"RECREATE");
   TTree *T = new TTree("TRee","data from ascii file");
   TNtuple data("data","CV","Voltage:Capacitance");
   cout<<TextDataName<<endl;
   cout<<"root"<<endl;
	 std:: ifstream inputFile(TextDataName);
	  std::string line="";
    //getline(inputFile,line,',');
    double Voltage, Capacitance ;
    string VoltageString, CapacitanceString ;
	  while(getline(inputFile,line)){
         if ( line[0]=='C' || line[0]=='D' || line[0]=='V'|| !line.length())
           {  continue; }
     else{
			stringstream ss(line);
			getline(ss,VoltageString,',');
			getline(ss,CapacitanceString,',');
			Voltage=stod(VoltageString);
			Capacitance=stod(CapacitanceString);
			//   sscanf(line.c_str(), "%lf[^,] , %lf[^,] %d\n", &Voltage , &Capacitance);
			//cout<<seperation<<","<<Cback<<endl;
			data.Fill(Voltage, Capacitance);

  }

   }
   data.Write();
   T->Write();
   f->Write();
   f->Close();
}

int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }
    while ((dirp = readdir(dp)) != NULL) {
		if((string(dirp->d_name)=="Cback_intersection.txt")||(string(dirp->d_name)=="TextToRoot.C"||(string(dirp->d_name)=="Cback@300V.txt"))
    ||(string(dirp->d_name)==".")||(string(dirp->d_name)==".."||string(dirp->d_name).find(".root")!=-1)){continue;}
        files.push_back(string(dirp->d_name));
      //  cout<<string(dirp->d_name)<<endl;
    }
    closedir(dp);
    return 0;
}


int TextToRoot()
{

	TCanvas *c1=new TCanvas("c1","CV",300,10,900,500);
	c1->SetGrid();
	c1->Divide(3,2);
	//  TCanvas *c2=new TCanvas("c1","CV",300,10,900,500);


	TMultiGraph *mg1 = new TMultiGraph();
	mg1->SetMinimum(0.0);
	mg1->SetMaximum(1000.0);
	mg1->SetTitle("CV : MOS : 10 kHz : Dose=0.0 kGy");
	//   gStyle->SetTitleFontSize(0.080);
	gStyle->SetTitleAlign(23);
	TMultiGraph *mg2 = new TMultiGraph();
	mg2->SetMinimum(0.0);
	mg2->SetMaximum(1000.0);
	mg2->SetTitle("CV : MOS : 10 kHz : Dose=15.4 kGy");
	//   gStyle->SetTitleFontSize(0.080);
	gStyle->SetTitleAlign(23);
	TMultiGraph *mg3 = new TMultiGraph();
	mg3->SetMinimum(0.0);
	mg3->SetMaximum(1000.0);
	mg3->SetTitle("CV : MOS : 10 kHz : Dose=28.8 kGy");
	//   gStyle->SetTitleFontSize(0.080);
	gStyle->SetTitleAlign(23);
	TMultiGraph *mg4 = new TMultiGraph();
	mg4->SetMinimum(0.0);
	mg4->SetMaximum(1000.0);
	mg4->SetTitle("CV : MOS : 10 kHz : Dose=44.2 kGy");
	//   gStyle->SetTitleFontSize(0.080);
	gStyle->SetTitleAlign(23);
	TMultiGraph *mg5 = new TMultiGraph();
	mg5->SetMinimum(0.0);
	mg5->SetMaximum(1000.0);
	mg5->SetTitle("CV : MOS : 10 kHz : Dose=59.5 kGy");
	//   gStyle->SetTitleFontSize(0.080);
	gStyle->SetTitleAlign(23);
	
	TMultiGraph *mg6 = new TMultiGraph();
	mg6->SetMinimum(0.0);
	mg6->SetMaximum(1000.0);
	mg6->SetTitle("CV : MOS : 10 kHz : Dose=73.9 kGy");
	//   gStyle->SetTitleFontSize(0.080);
	gStyle->SetTitleAlign(23);
	

	

	


	int markerstyle=20;
	int markercolor =2;


	TLegend *leg1 = new TLegend(0.75, 0.20, 0.95, 0.65);
	// leg-> SetNColumns(1);
	leg1->SetTextColor(kBlue);;
	leg1->SetTextAlign(12);
	leg1->SetTextAlign(12);
	leg1->SetNColumns(1);
	leg1->SetTextSize(0.030);
	
	TLegend *leg2 = new TLegend(0.75, 0.20, 0.95, 0.65);
	// leg-> SetNColumns(1);
	leg2->SetTextColor(kBlue);;
	leg2->SetTextAlign(12);
	leg2->SetTextAlign(12);
	leg2->SetNColumns(1);
	leg2->SetTextSize(0.030);
	
	TLegend *leg3 = new TLegend(0.75, 0.20, 0.95, 0.65);
	// leg-> SetNColumns(1);
	leg3->SetTextColor(kBlue);;
	leg3->SetTextAlign(12);
	leg3->SetTextAlign(12);
	leg3->SetNColumns(1);
	leg3->SetTextSize(0.030);

	TLegend *leg4 = new TLegend(0.75, 0.20, 0.95, 0.65);
	// leg-> SetNColumns(1);
	leg4->SetTextColor(kBlue);;
	leg4->SetTextAlign(12);
	leg4->SetTextAlign(12);
	leg4->SetNColumns(1);
	leg4->SetTextSize(0.030);
	
	TLegend *leg5 = new TLegend(0.75, 0.20, 0.95, 0.65);
	// leg-> SetNColumns(1);
	leg5->SetTextColor(kBlue);;
	leg5->SetTextAlign(12);
	leg5->SetTextAlign(12);
	leg5->SetNColumns(1);
	leg5->SetTextSize(0.030);

	TLegend *leg6 = new TLegend(0.75, 0.20, 0.95, 0.65);
	// leg-> SetNColumns(1);
	leg6->SetTextColor(kBlue);;
	leg6->SetTextAlign(12);
	leg6->SetTextAlign(12);
	leg6->SetNColumns(1);
	leg6->SetTextSize(0.030);




	string dir = string(".");  // Set the folder for search (".") for parent file
	vector<string> files = vector<string>(); // This vector will contain the names of each file in the folder after getdir function
	getdir(dir,files);

	sort_string_vector(files);
	cout<<files.size()<<endl;
        for (unsigned int k = 0; k<files.size();k++) {
            size_t pos1= files[k].find(".root");
            size_t pos= files[k].find(".csv");
            size_t pos2;
			size_t pos6;
            if(pos1==-1){
                cout << files[k] << endl;
                if(pos!=-1){	
					TGraph *gr1=new TGraph();
					TGraph *gr2=new TGraph();
					TGraph *gr3=new TGraph();
					TGraph *gr4=new TGraph();
					TGraph *gr5=new TGraph();
					TGraph *gr6=new TGraph();
					pos2=-1;
					pos6=-1;
					pos2= files[k].find("Dose=0.00Mrad");
					pos6= files[k].find("Dose=0.00Mrad_EXP");
					if((pos2!=-1)||(pos6!=-1)){
						string r=files[k];
						r=r.replace(r.begin()+pos,r.end(),".root");
						//char *root_name = new char[pos + 1];
						TString root_name=r.c_str();
						//std::strcpy(root_name, r.c_str());
						Convert_TestDataFile_To_RootTree(files[k],r);

						TFile* in_file=new TFile(root_name);
						double Voltage,Capacitance;
						float* row_content;

						TNtuple* data=(TNtuple*) in_file->GetObjectChecked("data","TNtuple");
						for(int irow=0; irow<data->GetEntries();++irow)
							{   data->GetEntry(irow);
								row_content=data->GetArgs();
								Voltage=row_content[0];
								Capacitance=row_content[1];
								cout<<"Voltage="<<Voltage<<","<<"Capacitance="<<Capacitance<<endl;
								gr1->SetPoint(irow,-1.0*Voltage,Capacitance*1e+12);
							}
						
						gr1->SetMarkerStyle(markerstyle);
						gr1->SetMarkerColor(markercolor);
						gr1->SetLineColor(markercolor);
						gr1->SetMarkerSize(1.2);
						gr1->GetXaxis()->SetTitle("Voltage [V]");
						gr1->GetYaxis()->SetTitle("Capacitance [pF]");
						mg1->Add(gr1);
						//if(pos6!=-1){leg1->AddEntry(gr1,"Exprimental","lp");}
						//leg1->AddEntry(gr1,files[k].substr(0,pos).c_str(),"lp");
						//leg1->Draw("apl");
					
						markerstyle++;
						markercolor++;
						if(markercolor==10){
						markercolor=30;
						}
						if(markercolor==0){
						markercolor=1;
						}
						if(markerstyle==49){
						markerstyle=20;
						}
						c1->cd(1);
							// pad.SetTitle("Total Capacitance Pixel sensors 50x50 with 150 thickness ");
							//pad.DrawFrame(0,0,55,1e-4);
							//TGaxis::SetMaxDigits(3);
							mg1->Draw("apl");
							mg1->GetXaxis()->SetTitle("Voltage [V]");
							mg1->GetYaxis()->SetTitle(" Capacitance [pF]");
							if(pos6!=-1){
								pos2=-1;
								leg1->AddEntry(gr1,"Exprimental","lp");
								leg1->Draw("apl");}
							if(pos2!=-1){
								pos6=-1;
								leg1->AddEntry(gr1,"TCAD Simulation","lp");
								leg1->Draw("apl");}

							gPad->Modified();
							gPad->Update();
					}
					
					pos2=-1;
					pos6=-1;
					pos2= files[k].find("Dose=1.54Mrad");
					pos6= files[k].find("Dose=1.54Mrad_EXP");
					if((pos2!=-1)||(pos6!=-1)){
						TGraph *gr2=new TGraph();
						string r=files[k];
						r=r.replace(r.begin()+pos,r.end(),".root");
						//char *root_name = new char[pos + 1];
						TString root_name=r.c_str();
						//std::strcpy(root_name, r.c_str());
						Convert_TestDataFile_To_RootTree(files[k],root_name);

						TFile* in_file=new TFile(root_name);
						double Voltage,Capacitance;
						float* row_content;

						TNtuple* data=(TNtuple*) in_file->GetObjectChecked("data","TNtuple");
						for(int irow=0; irow<data->GetEntries();++irow)
							{   data->GetEntry(irow);
								row_content=data->GetArgs();
								Voltage=row_content[0];
								Capacitance=row_content[1];
								cout<<"Voltage="<<Voltage<<","<<"Capacitance="<<Capacitance<<endl;
								gr2->SetPoint(irow,-1.0*Voltage,Capacitance*1e+12);
							}
						gr2->SetMarkerStyle(markerstyle);
						gr2->SetMarkerColor(markercolor);
						gr2->SetLineColor(markercolor);
						gr2->SetMarkerSize(1.2);
						gr2->GetXaxis()->SetTitle("Voltage [V]");
						gr2->GetYaxis()->SetTitle("Capacitance [pF]");
						mg2->Add(gr2);
						//if(pos2!=-1){leg2->AddEntry(gr2,"TCAD Simulation","lp");}
						//if(pos6!=-1){leg2->AddEntry(gr2,"Exprimental","lp");}
						//leg2->Draw("apl");
					
						markerstyle++;
						markercolor++;
						if(markercolor==10){
						markercolor=30;
						}
						if(markercolor==0){
						markercolor=1;
						}
						if(markerstyle==49){
						markerstyle=20;
						}
						c1->cd(2);
							// pad.SetTitle("Total Capacitance Pixel sensors 50x50 with 150 thickness ");
							//pad.DrawFrame(0,0,55,1e-4);
							//TGaxis::SetMaxDigits(3);
							mg2->Draw("apl");
							mg2->GetXaxis()->SetTitle("Voltage [V]");
							mg2->GetYaxis()->SetTitle(" Capacitance [pF]");
							if(pos6!=-1){
								pos2=-1;
								leg2->AddEntry(gr2,"Exprimental","lp");
								leg2->Draw("apl");}
							if(pos2!=-1){
								pos6=-1;
								leg2->AddEntry(gr2,"TCAD Simulation","lp");
								leg2->Draw("apl");}

							gPad->Modified();
							gPad->Update();
					}
					pos2=-1;
					pos6=-1;
					pos2= files[k].find("Dose=2.88Mrad");
					pos6= files[k].find("Dose=2.88Mrad_EXP");
					if((pos2!=-1)||(pos6!=-1)){
						TGraph *gr3=new TGraph();
						string r=files[k];
						r=r.replace(r.begin()+pos,r.end(),".root");
						//char *root_name = new char[pos + 1];
						TString root_name=r.c_str();
						//std::strcpy(root_name, r.c_str());
						Convert_TestDataFile_To_RootTree(files[k],r);

						TFile* in_file=new TFile(root_name);
						double Voltage,Capacitance;
						float* row_content;

						TNtuple* data=(TNtuple*) in_file->GetObjectChecked("data","TNtuple");
						for(int irow=0; irow<data->GetEntries();++irow)
							{   data->GetEntry(irow);
								row_content=data->GetArgs();
								Voltage=row_content[0];
								Capacitance=row_content[1];
								cout<<"Voltage="<<Voltage<<","<<"Capacitance="<<Capacitance<<endl;
								gr3->SetPoint(irow,-1.0*Voltage,Capacitance*1e+12);
							}
						gr3->SetMarkerStyle(markerstyle);
						gr3->SetMarkerColor(markercolor);
						gr3->SetLineColor(markercolor);
						gr3->SetMarkerSize(1.2);
						gr3->GetXaxis()->SetTitle("Voltage [V]");
						gr3->GetYaxis()->SetTitle("Capacitance [pF]");
						mg3->Add(gr3);
						//if(pos2!=-1){leg3->AddEntry(gr3,"TCAD Simulation","lp");}
						//if(pos6!=-1){leg3->AddEntry(gr3,"Exprimental","lp");}
						//leg3->Draw("apl");
					
						markerstyle++;
						markercolor++;
						if(markercolor==10){
						markercolor=30;
						}
						if(markercolor==0){
						markercolor=1;
						}
						if(markerstyle==49){
						markerstyle=20;
						}
						c1->cd(3);
							// pad.SetTitle("Total Capacitance Pixel sensors 50x50 with 150 thickness ");
							//pad.DrawFrame(0,0,55,1e-4);
							//TGaxis::SetMaxDigits(3);
							mg3->Draw("apl");
							mg3->GetXaxis()->SetTitle("Voltage [V]");
							mg3->GetYaxis()->SetTitle(" Capacitance [pF]");
							if(pos6!=-1){
								pos2=-1;
								leg3->AddEntry(gr3,"Exprimental","lp");
								leg3->Draw("apl");}
							if(pos2!=-1){
								pos6=-1;
								leg3->AddEntry(gr3,"TCAD Simulation","lp");
								leg3->Draw("apl");}

							gPad->Modified();
							gPad->Update();
					}
					pos2=-1;
					pos6=-1;
					pos2= files[k].find("Dose=4.42Mrad");
					pos6= files[k].find("Dose=4.42Mrad_EXP");
					if((pos2!=-1)||(pos6!=-1)){
						TGraph *gr3=new TGraph();
						string r=files[k];
						r=r.replace(r.begin()+pos,r.end(),".root");
						//char *root_name = new char[pos + 1];
						TString root_name=r.c_str();
						//std::strcpy(root_name, r.c_str());
						Convert_TestDataFile_To_RootTree(files[k],r);

						TFile* in_file=new TFile(root_name);
						double Voltage,Capacitance;
						float* row_content;

						TNtuple* data=(TNtuple*) in_file->GetObjectChecked("data","TNtuple");
						for(int irow=0; irow<data->GetEntries();++irow)
							{   data->GetEntry(irow);
								row_content=data->GetArgs();
								Voltage=row_content[0];
								Capacitance=row_content[1];
								cout<<"Voltage="<<Voltage<<","<<"Capacitance="<<Capacitance<<endl;
								gr4->SetPoint(irow,-1.0*Voltage,Capacitance*1e+12);
							}
						gr4->SetMarkerStyle(markerstyle);
						gr4->SetMarkerColor(markercolor);
						gr4->SetLineColor(markercolor);
						gr4->SetMarkerSize(1.2);
						gr4->GetXaxis()->SetTitle("Voltage [V]");
						gr4->GetYaxis()->SetTitle("Capacitance [pF]");
						mg4->Add(gr4);
						//if(pos2!=-1){leg4->AddEntry(gr4,"TCAD Simulation","lp");}
						//if(pos6!=-1){leg4->AddEntry(gr4,"Exprimental","lp");}
						//leg3->Draw("apl");
					
						markerstyle++;
						markercolor++;
						if(markercolor==10){
						markercolor=30;
						}
						if(markercolor==0){
						markercolor=1;
						}
						if(markerstyle==49){
						markerstyle=20;
						}
						c1->cd(4);
							// pad.SetTitle("Total Capacitance Pixel sensors 50x50 with 150 thickness ");
							//pad.DrawFrame(0,0,55,1e-4);
							//TGaxis::SetMaxDigits(3);
							mg4->Draw("apl");
							mg4->GetXaxis()->SetTitle("Voltage [V]");
							mg4->GetYaxis()->SetTitle(" Capacitance [pF]");
							if(pos6!=-1){
								pos2=-1;
								leg4->AddEntry(gr4,"Exprimental","lp");
								leg4->Draw("apl");}
							if(pos2!=-1){
								pos6=-1;
								leg4->AddEntry(gr4,"TCAD Simulation","lp");
								leg4->Draw("apl");}

							gPad->Modified();
							gPad->Update();
					}
					pos2=-1;
					pos6=-1;
					pos2= files[k].find("Dose=5.95Mrad");
					pos6= files[k].find("Dose=5.95Mrad_EXP");
					if((pos2!=-1)||(pos6!=-1)){
						TGraph *gr5=new TGraph();
						string r=files[k];
						r=r.replace(r.begin()+pos,r.end(),".root");
						//char *root_name = new char[pos + 1];
						TString root_name=r.c_str();
						//std::strcpy(root_name, r.c_str());
						Convert_TestDataFile_To_RootTree(files[k],r);

						TFile* in_file=new TFile(root_name);
						double Voltage,Capacitance;
						float* row_content;

						TNtuple* data=(TNtuple*) in_file->GetObjectChecked("data","TNtuple");
						for(int irow=0; irow<data->GetEntries();++irow)
							{   data->GetEntry(irow);
								row_content=data->GetArgs();
								Voltage=row_content[0];
								Capacitance=row_content[1];
								cout<<"Voltage="<<Voltage<<","<<"Capacitance="<<Capacitance<<endl;
								gr5->SetPoint(irow,-1.0*Voltage,Capacitance*1e+12);
							}
						gr5->SetMarkerStyle(markerstyle);
						gr5->SetMarkerColor(markercolor);
						gr5->SetLineColor(markercolor);
						gr5->SetMarkerSize(1.2);
						gr5->GetXaxis()->SetTitle("Voltage [V]");
						gr5->GetYaxis()->SetTitle("Capacitance [pF]");
						mg5->Add(gr5);
						//if(pos2!=-1){leg5->AddEntry(gr5,"TCAD Simulation","lp");}
						//if(pos6!=-1){leg5->AddEntry(gr5,"Exprimental","lp");}
						//leg5->Draw("apl");
						
						markerstyle++;
						markercolor++;
						if(markercolor==10){
						markercolor=30;
						}
						if(markercolor==0){
						markercolor=1;
						}
						if(markerstyle==49){
						markerstyle=20;
						}
						c1->cd(5);
							// pad.SetTitle("Total Capacitance Pixel sensors 50x50 with 150 thickness ");
							//pad.DrawFrame(0,0,55,1e-4);
							//TGaxis::SetMaxDigits(3);
							mg5->Draw("apl");
							mg5->GetXaxis()->SetTitle("Voltage [V]");
							mg5->GetYaxis()->SetTitle(" Capacitance [pF]");
							if(pos6!=-1){
								pos2=-1;
								leg5->AddEntry(gr5,"Exprimental","lp");
								leg5->Draw("apl");}
							if(pos2!=-1){
								pos6=-1;
								leg5->AddEntry(gr5,"TCAD Simulation","lp");
								leg5->Draw("apl");}

							gPad->Modified();
							gPad->Update();
					}
					pos2=-1;
					pos6=-1;
					pos2= files[k].find("Dose=7.39Mrad");
					pos6= files[k].find("Dose=7.39Mrad_EXP");
					if((pos2!=-1)||(pos6!=-1)){
						TGraph *gr4=new TGraph();
						string r=files[k];
						r=r.replace(r.begin()+pos,r.end(),".root");
						//char *root_name = new char[pos + 1];
						TString root_name=r.c_str();
						//std::strcpy(root_name, r.c_str());
						Convert_TestDataFile_To_RootTree(files[k],r);

						TFile* in_file=new TFile(root_name);
						double Voltage,Capacitance;
						float* row_content;

						TNtuple* data=(TNtuple*) in_file->GetObjectChecked("data","TNtuple");
						for(int irow=0; irow<data->GetEntries();++irow)
							{   data->GetEntry(irow);
								row_content=data->GetArgs();
								Voltage=row_content[0];
								Capacitance=row_content[1];
								cout<<"Voltage="<<Voltage<<","<<"Capacitance="<<Capacitance<<endl;
								gr6->SetPoint(irow,-1.0*Voltage,Capacitance*1e+12);
							}
						gr6->SetMarkerStyle(markerstyle);
						gr6->SetMarkerColor(markercolor);
						gr6->SetLineColor(markercolor);
						gr6->SetMarkerSize(1.2);
						gr6->GetXaxis()->SetTitle("Voltage [V]");
						gr6->GetYaxis()->SetTitle("Capacitance [pF]");
						mg6->Add(gr6);
						//if(pos2!=-1){leg6->AddEntry(gr6,"TCAD Simulation","lp");}
						//if(pos6!=-1){leg6->AddEntry(gr6,"Exprimental","lp");}
						//leg4->Draw("apl");
						
						markerstyle++;
						markercolor++;
						if(markercolor==10){
						markercolor=30;
						}
						if(markercolor==0){
						markercolor=1;
						}
						if(markerstyle==49){
						markerstyle=20;
						}
						c1->cd(6);
							// pad.SetTitle("Total Capacitance Pixel sensors 50x50 with 150 thickness ");
							//pad.DrawFrame(0,0,55,1e-4);
							//TGaxis::SetMaxDigits(3);
							mg6->Draw("apl");
							mg6->GetXaxis()->SetTitle("Voltage [V]");
							mg6->GetYaxis()->SetTitle(" Capacitance [pF]");
							if(pos6!=-1){
								pos2=-1;
								leg6->AddEntry(gr6,"Exprimental","lp");
								leg5->Draw("apl");}
							if(pos2!=-1){
								pos6=-1;
								leg6->AddEntry(gr6,"TCAD Simulation","lp");
								leg6->Draw("apl");}

							gPad->Modified();
							gPad->Update();
					}
				
				}	
			}
		}	
		c1->Draw();
	return 0;
}
