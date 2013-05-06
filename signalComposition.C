{

  int nCats=9;

  TString catName[nCats]={
    "Untagged 0",
    "Untagged 1",
    "Untagged 2",
    "Untagged 3",
    "Di-jet Tight",
    "Di-jet Loose",
    "Muon",
    "Electron",
    "MET"
  };
  
  TString processName[4]={
    "ggH",
    "qqH",
    "VH",
    "ttH"
  };

  float signal_composition[nCats][4]={
    72.9,11.6,12.9,2.6, //untag0
    83.5,8.4,7.1,1, //untag1
    91.6,4.5,3.6,0.4, //untag2
    92.5,3.9,3.3,0.3, //untag3
    20.7,78.9,0.3,0.1, //dijet tight
    47.0,50.9,1.7,0.5, //dijet loose
    0,0.2,79,20.8, //muon 
    1.1,0.4,78.7,19.8, //electron
    22,2.6,63.7,11.7 //MET
  };

  TH1F* signalHistoFrac[4];

  for (int i=0;i<4;++i)
    {
      signalHistoFrac[i]=new TH1F(Form("frac_%s",processName[i].Data()),Form("frac_%s",processName[i].Data()),nCats,-0.5,nCats-0.5);
      std::cout <<"+++++++++++++++++ " << processName[i] << " ++++++++++++++++++++" << std::endl;
      for (int j=0;j<nCats;++j)
	{
	  signalHistoFrac[i]->SetBinContent(j+1,signal_composition[j][i]);
	  std::cout << catName[j] << ": " <<  signalHistoFrac[i]->GetBinContent(j+1) << "%" << std::endl;
	}
    }

  signalHistoFrac[0]->SetFillColor(kGreen);
  signalHistoFrac[1]->SetFillColor(kRed);
  signalHistoFrac[2]->SetFillColor(kCyan);
  signalHistoFrac[3]->SetFillColor(kAzure);  


  gStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  //  gStyle->SetPadTickY(1);  // To get tick marks on the opposite side of the frame

  TCanvas *Plots = new TCanvas("Plots", "Plots",1,1,800,776);
  gStyle->SetOptStat(0);
  Plots->SetHighLightColor(2);
  Plots->Range(-14.67532,-1.75,11.2987,15.75);
  Plots->SetFillColor(0);
  Plots->SetBorderMode(0);
  Plots->SetBorderSize(2);
  Plots->SetTopMargin(0.16);
  Plots->SetLeftMargin(0.18);
  Plots->SetRightMargin(0.05);
  Plots->SetFrameBorderMode(0);
  Plots->SetFrameBorderMode(0);


  TH2F *dummy = new TH2F("dummy","",10,0.,100.,nCats,-0.5,nCats-0.5);
  dummy->SetStats(0);

  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  //gStyle_->SetPadTickY(1);
  
  Int_t ci;   // for color index setting
  ci = TColor::GetColor("#00ff00");
  dummy->SetFillColor(ci);


  for (int i=0;i<nCats;++i)
    dummy->GetYaxis()->SetBinLabel(nCats-i,catName[i]);
  
  dummy->GetYaxis()->SetTickLength(0);
  
  dummy->GetXaxis()->SetTitle("Signal Fraction (%)");
  dummy->GetXaxis()->SetNdivisions(510);
  
  dummy->GetXaxis()->SetLabelFont(42);
  dummy->GetXaxis()->SetLabelSize(0.045);
  dummy->GetXaxis()->SetTitleSize(0.045);
  dummy->GetXaxis()->SetTitleOffset(0.95);
  dummy->GetXaxis()->SetTitleFont(42);
  dummy->GetYaxis()->SetNdivisions(510);

   dummy->GetYaxis()->SetLabelSize(0.045);
   dummy->GetYaxis()->SetTitleSize(0.045);
   dummy->GetYaxis()->SetTitleOffset(1.1);
   dummy->GetYaxis()->SetTitleFont(42);
   dummy->GetZaxis()->SetLabelFont(42);
   dummy->GetZaxis()->SetLabelSize(0.035);
   dummy->GetZaxis()->SetTitleSize(0.035);
   dummy->GetZaxis()->SetTitleFont(42);
   dummy->Draw("");


   
  //loop on bins and draw a TPave
  Int_t nbins  = nCats;
  Float_t xmin = 0;
  Float_t xmax = 100;


  Float_t ymin = 0.0;
  Float_t ymax = 100;
  Float_t width = 0.34;

  TPave *pave;
  for (Int_t i=0;i<nbins;i++) {

    Float_t ybin = signalHistoFrac[0]->GetBinCenter(i+1);
    Float_t ybinmin = ybin -width*signalHistoFrac[0]->GetBinWidth(i+1);
    Float_t ybinmax = ybin +width*signalHistoFrac[0]->GetBinWidth(i+1);

    Float_t xbinmin = ymin;
    Float_t xbinmax = ymin;

    //Stacked fractions
    for (int j=0;j<4;++j)
      {
	xbinmax+=signalHistoFrac[j]->GetBinContent(nbins-i);
	pave = new TPave(xbinmin,ybinmin,xbinmax,ybinmax);
	pave->SetFillColor(signalHistoFrac[j]->GetFillColor());
	pave->Draw();
	pave->SetBorderSize(0);
	xbinmin+=signalHistoFrac[j]->GetBinContent(nbins-i);
      }
  }
  

  TLatex *   tex_m=new TLatex();
  tex_m->SetNDC();
  tex_m->SetTextAlign(12);
  tex_m->SetTextSize(0.03);
  tex_m->SetLineWidth(2);



  pave=new TPave(0.20,0.85,0.23,0.85+0.03,0,"NDC");
  pave->SetFillColor(signalHistoFrac[0]->GetFillColor());
  pave->Draw();
  tex_m->DrawLatex(0.24,0.84+0.025,"ggH");

  pave=new TPave(0.38,0.85,0.41,0.85+0.03,0,"NDC");
  pave->SetFillColor(signalHistoFrac[1]->GetFillColor());
  pave->Draw();
  tex_m->DrawLatex(0.42,0.84+0.025,"qqH");

  pave=new TPave(0.56,0.85,0.59,0.85+0.03,0,"NDC");
  pave->SetFillColor(signalHistoFrac[2]->GetFillColor());
  pave->Draw();
  tex_m->DrawLatex(0.60,0.84+0.025,"VH");

  pave=new TPave(0.74,0.85,0.77,0.85+0.03,0,"NDC");
  pave->SetFillColor(signalHistoFrac[3]->GetFillColor());
  pave->Draw();
  tex_m->DrawLatex(0.78,0.84+0.025,"ttH");

  tex_m->SetTextSize(0.045);
  tex_m->DrawLatex(0.11,0.935,"CMS Simulation          H#rightarrow#gamma#gamma (m_{H}=125 GeV/c^{2})");

  TLine *line = new TLine(0,nCats-4.5,100,nCats-4.5);
  line->SetLineColor(kBlack);
  line->SetLineWidth(2);
  line->SetLineStyle(2);
  line->Draw();

  TLine *line = new TLine(0,nCats-6.5,100,nCats-6.5);
  line->SetLineColor(kBlack);
  line->SetLineWidth(2);
  line->SetLineStyle(2);
  line->Draw();

  Plots->RedrawAxis();

  Plots->SaveAs("signalComposition.png");
  Plots->SaveAs("signalComposition.pdf");

}

