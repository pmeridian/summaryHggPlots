{

  gStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  gStyle->SetPadTickY(1);  // To get tick marks on the opposite side of the frame

  TCanvas *Plots = new TCanvas("Plots", "Plots",1,1,800,776);
  gStyle->SetOptStat(0);
  Plots->SetHighLightColor(2);
  Plots->Range(-14.67532,-1.75,11.2987,15.75);
  Plots->SetFillColor(0);
  Plots->SetBorderMode(0);
  Plots->SetBorderSize(2);
  Plots->SetLeftMargin(0.15);
  Plots->SetRightMargin(0.05);
  Plots->SetFrameBorderMode(0);
  Plots->SetFrameBorderMode(0);

  float sigExp_CMS_MVA[3]={1.75,2.65,4.2};
  float sigObs_CMS_MVA[3]={2.9,4.1,3.2};
  float mu_CMS_MVA[3]={1.6,1.56,0.78};
  float mu_errUp_CMS_MVA[3]={0.58,0.43,0.27};
  float mu_errDown_CMS_MVA[3]={0.58,0.43,0.27};

  float mu_errAvg_CMS_MVA[3];
  for (int i=0;i<3;++i)
      mu_errAvg_CMS_MVA[i]=0.5*(mu_errUp_CMS_MVA[i]+mu_errDown_CMS_MVA[i]);

  float sigExp_CMS_CUT[3]={1.34,2.23,3.5};
  float sigObs_CMS_CUT[3]={3.0,3.7,3.9};
  float mu_CMS_CUT[3]={2.1,1.66,1.11};
  float mu_errUp_CMS_CUT[3]={0.75,0.45,0.31};
  float mu_errDown_CMS_CUT[3]={0.75,0.55,0.31};

  float mu_errAvg_CMS_CUT[3];
  for (int i=0;i<3;++i)
    mu_errAvg_CMS_CUT[i]=0.5*(mu_errUp_CMS_CUT[i]+mu_errDown_CMS_CUT[i]);

  float lumi_CMS[3]={4.8,5.1+5.3,5.1+19.6};
  float lumi_CMS_err[3]={0.,0.,0.};

  float lumi_CMS_2[3]={4.8+0.2,5.1+5.3+0.2,5.1+19.6+0.2};

  float sigExp_ATLAS[4]={1.32,2.46,3.3,4.1};
  float sigObs_ATLAS[4]={2.8,4.5,6.1,7.4};
  float mu_ATLAS[4]={2.0,1.9,1.8,1.65};
  float mu_errUp_ATLAS[4]={0.75,0.5,0.42,0.34};
  float mu_errDown_ATLAS[4]={0.75,0.5,0.36,0.30};

  float mu_errAvg_ATLAS[3];
  for (int i=0;i<4;++i)
    mu_errAvg_ATLAS[i]=0.5*(mu_errUp_ATLAS[i]+mu_errDown_ATLAS[i]);

  float lumi_ATLAS[4]={4.9,4.8+5.9,4.8+13,4.8+20.7};
  float lumi_ATLAS_err[4]={0.,0.,0.};

  TF1 sigExp_CMS_MVA_lumiScaled("sigExp_CMS_MVA_lumiScaled","2.65*TMath::Sqrt(x)/TMath::Sqrt(5.1+5.3)",0.,30.);
  TF1 sigExp_CMS_CUT_lumiScaled("sigExp_CMS_CUT_lumiScaled","2.23*TMath::Sqrt(x)/TMath::Sqrt(5.1+5.3)",0.,30.);
  TF1 sigExp_ATLAS_lumiScaled("sigExp_ATLAS_lumiScaled","2.46*TMath::Sqrt(x)/TMath::Sqrt(4.8+5.9)",0.,30.);

  //  TF1 mu_errAvg_CMS_MVA_lumiScaled("sigExp_CMS_CUT_lumiScaled","TMath::Sqrt(1.045*1.045/x+0.165*0.165)",3.,30.);
  TF1 mu_errAvg_CMS_MVA_lumiScaled("sigExp_CMS_MVA_lumiScaled","TMath::Sqrt(1.343*1.343/x)",3,30.);
  //  TF1 mu_errAvg_CMS_CUT_lumiScaled("sigExp_CMS_CUT_lumiScaled","TMath::Sqrt(1.194*1.194/x+0.195*0.195)",3.,30.);
  TF1 mu_errAvg_CMS_CUT_lumiScaled("sigExp_CMS_CUT_lumiScaled","TMath::Sqrt(1.542*1.542/x)",3.,30.);
  //  TF1 mu_errAvg_ATLAS_lumiScaled("sigExp_ATLAS_lumiScaled","TMath::Sqrt(1.217*1.217/x+0.21*0.21)",3.,30.);
  TF1 mu_errAvg_ATLAS_lumiScaled("sigExp_ATLAS_lumiScaled","TMath::Sqrt(1.616*1.616/x)",3.,30.);

  TF1 sigObs_ATLAS_lumiScaled("sigExp_ATLAS_lumiScaled","4.5*TMath::Sqrt(x)/TMath::Sqrt(4.8+5.9)",0.,30.);

  TF1 errVsLumi("errVsLumi","TMath::Sqrt(([0]*[0]/x)+[1]*[1])",0.1,30.);
  errVsLumi.SetParameter(0,2);
  errVsLumi.SetParameter(1,0.1);

  TGraph* sigExp_CMS_MVA_graph=new TGraph(3,lumi_CMS,sigExp_CMS_MVA);
  TGraph* sigObs_CMS_MVA_graph=new TGraph(3,lumi_CMS,sigObs_CMS_MVA);
  TGraph* mu_errAvg_CMS_MVA_graph=new TGraph(3,lumi_CMS,mu_errAvg_CMS_MVA);
  TGraphAsymmErrors* mu_CMS_MVA_graph=new TGraphAsymmErrors(3,lumi_CMS,mu_CMS_MVA,lumi_CMS_err,lumi_CMS_err,mu_errDown_CMS_MVA,mu_errUp_CMS_CUT); 

  TGraph* sigExp_CMS_CUT_graph=new TGraph(3,lumi_CMS,sigExp_CMS_CUT);
  TGraph* sigObs_CMS_CUT_graph=new TGraph(3,lumi_CMS,sigObs_CMS_CUT);
  TGraph* mu_errAvg_CMS_CUT_graph=new TGraph(3,lumi_CMS,mu_errAvg_CMS_CUT);
  TGraphAsymmErrors* mu_CMS_CUT_graph=new TGraphAsymmErrors(3,lumi_CMS_2,mu_CMS_CUT,lumi_CMS_err,lumi_CMS_err,mu_errDown_CMS_CUT,mu_errUp_CMS_CUT); 

  TGraph* sigExp_ATLAS_graph=new TGraph(4,lumi_ATLAS,sigExp_ATLAS);
  TGraph* sigObs_ATLAS_graph=new TGraph(4,lumi_ATLAS,sigObs_ATLAS);
  TGraph* mu_errAvg_ATLAS_graph=new TGraph(4,lumi_ATLAS,mu_errAvg_ATLAS);
  TGraphAsymmErrors* mu_ATLAS_graph=new TGraphAsymmErrors(4,lumi_ATLAS,mu_ATLAS,lumi_ATLAS_err,lumi_ATLAS_err,mu_errDown_ATLAS,mu_errUp_ATLAS); 

  sigExp_CMS_MVA_graph->SetMarkerStyle(20);
  sigExp_CMS_MVA_graph->SetMarkerSize(1.4);
  sigExp_CMS_MVA_graph->SetMarkerColor(kAzure);

  mu_CMS_MVA_graph->SetMarkerStyle(20);
  mu_CMS_MVA_graph->SetMarkerSize(1.4);
  mu_CMS_MVA_graph->SetMarkerColor(kAzure);

  mu_errAvg_CMS_MVA_graph->SetMarkerStyle(20);
  mu_errAvg_CMS_MVA_graph->SetMarkerSize(1.4);
  mu_errAvg_CMS_MVA_graph->SetMarkerColor(kAzure);
  mu_errAvg_CMS_MVA_graph->SetLineColor(kAzure);
  mu_errAvg_CMS_MVA_graph->SetLineWidth(2);

  sigObs_CMS_MVA_graph->SetMarkerStyle(24);
  sigObs_CMS_MVA_graph->SetMarkerSize(1.4);
  sigObs_CMS_MVA_graph->SetMarkerColor(kAzure);

  sigExp_CMS_MVA_lumiScaled.SetLineColor(kAzure);
  mu_errAvg_CMS_MVA_lumiScaled.SetLineColor(kAzure);

  sigExp_CMS_CUT_graph->SetMarkerStyle(21);
  sigExp_CMS_CUT_graph->SetMarkerSize(1.4);
  sigExp_CMS_CUT_graph->SetMarkerColor(kAzure);

  mu_CMS_CUT_graph->SetMarkerStyle(21);
  mu_CMS_CUT_graph->SetMarkerSize(1.4);
  mu_CMS_CUT_graph->SetMarkerColor(kAzure);

  mu_errAvg_CMS_CUT_graph->SetMarkerStyle(21);
  mu_errAvg_CMS_CUT_graph->SetMarkerSize(1.4);
  mu_errAvg_CMS_CUT_graph->SetMarkerColor(kAzure);
  mu_errAvg_CMS_CUT_graph->SetLineColor(kAzure);
  mu_errAvg_CMS_CUT_graph->SetLineWidth(2);
  mu_errAvg_CMS_CUT_graph->SetLineStyle(2);

  sigObs_CMS_CUT_graph->SetMarkerStyle(25);
  sigObs_CMS_CUT_graph->SetMarkerSize(1.4);
  sigObs_CMS_CUT_graph->SetMarkerColor(kAzure);

  sigExp_CMS_CUT_lumiScaled.SetLineColor(kAzure);
  sigExp_CMS_CUT_lumiScaled.SetLineStyle(2);

  mu_errAvg_CMS_CUT_lumiScaled.SetLineColor(kAzure);
  mu_errAvg_CMS_CUT_lumiScaled.SetLineStyle(2);

  sigExp_ATLAS_graph->SetMarkerStyle(22);
  sigExp_ATLAS_graph->SetMarkerSize(1.4);
  sigExp_ATLAS_graph->SetMarkerColor(kMagenta);


  mu_ATLAS_graph->SetMarkerStyle(22);
  mu_ATLAS_graph->SetMarkerSize(1.4);
  mu_ATLAS_graph->SetMarkerColor(kMagenta);

  mu_errAvg_ATLAS_graph->SetMarkerStyle(22);
  mu_errAvg_ATLAS_graph->SetMarkerSize(1.4);
  mu_errAvg_ATLAS_graph->SetMarkerColor(kMagenta);
  mu_errAvg_ATLAS_graph->SetLineColor(kMagenta);
  mu_errAvg_ATLAS_graph->SetLineWidth(2);


  sigObs_ATLAS_graph->SetMarkerStyle(26);
  sigObs_ATLAS_graph->SetMarkerSize(1.4);
  sigObs_ATLAS_graph->SetMarkerColor(kMagenta);

  sigExp_ATLAS_lumiScaled.SetLineColor(kMagenta);
  mu_errAvg_ATLAS_lumiScaled.SetLineColor(kMagenta);
  sigObs_ATLAS_lumiScaled.SetLineColor(kMagenta+3);



  TH2F *dummy = new TH2F("dummy","",4,0.,30.,10,0.,12.);
  dummy->SetStats(0);


  //gStyle_->SetPadTickY(1);

  Int_t ci;   // for color index setting
  ci = TColor::GetColor("#00ff00");
  dummy->SetFillColor(ci);

  dummy->GetXaxis()->SetTitle("L (fb^{-1})");
  dummy->GetXaxis()->SetNdivisions(510);
  dummy->GetXaxis()->SetLabelFont(42);
  dummy->GetXaxis()->SetLabelSize(0.045);
  dummy->GetXaxis()->SetTitleSize(0.045);
  dummy->GetXaxis()->SetTitleOffset(0.95);
  dummy->GetXaxis()->SetTitleFont(42);
  dummy->GetYaxis()->SetNdivisions(510);
  dummy->GetYaxis()->SetTitle("Significance (#sigma)");
//   dummy->GetYaxis()->SetBinLabel(1,"H#rightarrowWW");
//   dummy->GetYaxis()->SetBinLabel(2,"H#rightarrowZZ");
//   dummy->GetYaxis()->SetBinLabel(3,"H#rightarrow#gamma#gamma");
  dummy->GetYaxis()->SetLabelSize(0.045);
  dummy->GetYaxis()->SetTitleSize(0.045);
  dummy->GetYaxis()->SetTitleOffset(1.1);
  dummy->GetYaxis()->SetTitleFont(42);
  dummy->GetZaxis()->SetLabelFont(42);
  dummy->GetZaxis()->SetLabelSize(0.035);
  dummy->GetZaxis()->SetTitleSize(0.035);
  dummy->GetZaxis()->SetTitleFont(42);
  dummy->Draw("");

  sigExp_CMS_MVA_lumiScaled.Draw("SAME");
  sigExp_CMS_CUT_lumiScaled.Draw("SAME");
  sigExp_ATLAS_lumiScaled.Draw("SAME");
  sigObs_ATLAS_lumiScaled.Draw("SAME");

  sigExp_CMS_MVA_graph->Draw("PSAME");
  sigExp_CMS_CUT_graph->Draw("PSAME");
  sigExp_ATLAS_graph->Draw("PSAME");

  sigObs_CMS_MVA_graph->Draw("PSAME");
  sigObs_CMS_CUT_graph->Draw("PSAME");
  sigObs_ATLAS_graph->Draw("PSAME");


  TLegend a(0.155,0.6,0.42,0.88);
  a.SetFillColor(0);
  a.SetBorderSize(0);
  a.AddEntry(sigExp_CMS_MVA_graph,"CMS MVA Exp #sigma","P");
  a.AddEntry(sigObs_CMS_MVA_graph,"CMS MVA Obs #sigma","P");
  a.AddEntry(sigExp_CMS_CUT_graph,"CMS CUT Exp #sigma","P");
  a.AddEntry(sigObs_CMS_CUT_graph,"CMS CUT Obs #sigma","P");
  a.AddEntry(sigExp_ATLAS_graph,"ATLAS Exp #sigma","P");
  a.AddEntry(sigObs_ATLAS_graph,"ATLAS Obs #sigma","P");

  a.AddEntry(&sigObs_ATLAS_lumiScaled,"1.37 #times #sqrt{L}","L");
  a.AddEntry(&sigExp_CMS_MVA_lumiScaled,"0.82 #times #sqrt{L}","L");
  a.AddEntry(&sigExp_ATLAS_lumiScaled,"0.75 #times #sqrt{L}","L");
  a.AddEntry(&sigExp_CMS_CUT_lumiScaled,"0.69 #times #sqrt{L}","L");
  a.Draw();

  TLatex *   tex_m=new TLatex();
  tex_m->SetNDC();
  tex_m->SetTextAngle(90);
  tex_m->SetTextAlign(12);
  tex_m->SetTextSize(0.02);
  tex_m->SetLineWidth(2);
  tex_m->DrawLatex(0.27,0.35,"#splitline{CMS-PAS-HIG-11-033}{CMS-PAS-HIG-12-001}");
  tex_m->DrawLatex(0.296,0.35,"ATLAS-CONF-2011-161");

  tex_m->DrawLatex(0.435,0.435,"#splitline{CMS-PAS-HIG-12-015}{ATLAS-CONF-2012-091}");

  tex_m->DrawLatex(0.62,0.56,"ATLAS-CONF-2012-168");

  tex_m->DrawLatex(0.82,0.63,"#splitline{CMS-PAS-HIG-13-001}{ATLAS-CONF-2013-012}");


  tex_m->SetTextAngle(0);
  tex_m->DrawLatex(0.23,0.15,"Moriond 2012");
  tex_m->DrawLatex(0.4,0.213,"ICHEP 2012");
  tex_m->DrawLatex(0.77,0.29.,"Moriond 2013");

  Plots->SaveAs("significanceWithTime.png");
  Plots->SaveAs("significanceWithTime.pdf");


  TH2F *dummy = new TH2F("dummy","",4,0.,30.,10,0.,4.);
  dummy->SetStats(0);


  //gStyle_->SetPadTickY(1);

  Int_t ci;   // for color index setting
  ci = TColor::GetColor("#00ff00");
  dummy->SetFillColor(ci);

  dummy->GetXaxis()->SetTitle("L (fb^{-1})");
  dummy->GetXaxis()->SetNdivisions(510);
  dummy->GetXaxis()->SetLabelFont(42);
  dummy->GetXaxis()->SetLabelSize(0.045);
  dummy->GetXaxis()->SetTitleSize(0.045);
  dummy->GetXaxis()->SetTitleOffset(0.95);
  dummy->GetXaxis()->SetTitleFont(42);
  dummy->GetYaxis()->SetNdivisions(510);
  dummy->GetYaxis()->SetTitle("Signal strength #sigma/#sigma_{SM} (#mu)");
//   dummy->GetYaxis()->SetBinLabel(1,"H#rightarrowWW");
//   dummy->GetYaxis()->SetBinLabel(2,"H#rightarrowZZ");
//   dummy->GetYaxis()->SetBinLabel(3,"H#rightarrow#gamma#gamma");
  dummy->GetYaxis()->SetLabelSize(0.045);
  dummy->GetYaxis()->SetTitleSize(0.045);
  dummy->GetYaxis()->SetTitleOffset(1.2);
  dummy->GetYaxis()->SetTitleFont(42);
  dummy->GetZaxis()->SetLabelFont(42);
  dummy->GetZaxis()->SetLabelSize(0.035);
  dummy->GetZaxis()->SetTitleSize(0.035);
  dummy->GetZaxis()->SetTitleFont(42);
  dummy->Draw("");


  TLine *line = new TLine(0,1,30,1);
  line->SetLineColor(kBlue);
  line->SetLineWidth(2);
  line->SetLineStyle(2);
  line->Draw();

  mu_CMS_MVA_graph->Draw("PSAME");
  mu_CMS_CUT_graph->Draw("PSAME");
  mu_ATLAS_graph->Draw("PSAME");

  TLegend a(0.65,0.7,0.9,0.88);
  a.SetFillColor(0);
  a.SetBorderSize(0);
  a.AddEntry(mu_CMS_MVA_graph,"CMS MVA #mu","PL");
  a.AddEntry(mu_CMS_CUT_graph,"CMS CUT #mu","PL");
  a.AddEntry(mu_ATLAS_graph,"ATLAS #mu","PL");


  a.Draw();


  TLatex *   tex_m=new TLatex();
  tex_m->SetNDC();
  tex_m->SetTextAngle(90);
  tex_m->SetTextAlign(12);
  tex_m->SetTextSize(0.02);
  tex_m->SetLineWidth(2);
  tex_m->DrawLatex(0.27-0.025,0.47,"CMS-PAS-HIG-11-033");
  tex_m->DrawLatex(0.27-0.025,0.47-0.2,"CMS-PAS-HIG-12-001");
  tex_m->DrawLatex(0.27+0.045,0.47-0.05,"ATLAS-CONF-2011-161");

  tex_m->DrawLatex(0.435-0.035,0.47-0.2,"CMS-PAS-HIG-12-015");
  tex_m->DrawLatex(0.435+0.035,0.47-0.08,"ATLAS-CONF-2012-091");

  tex_m->DrawLatex(0.62+0.035,0.47-0.12,"ATLAS-CONF-2012-168");

  tex_m->DrawLatex(0.82-0.05,0.47-0.25,"CMS-PAS-HIG-13-001");
  tex_m->DrawLatex(0.82+0.035,0.47-0.15,"ATLAS-CONF-2013-012");

  tex_m->SetTextAngle(0);
  tex_m->DrawLatex(0.23,0.25,"Moriond 2012");
  tex_m->DrawLatex(0.4,0.23,"ICHEP 2012");
  tex_m->DrawLatex(0.77,0.17.,"Moriond 2013");

  Plots->SaveAs("muWithTime.png");
  Plots->SaveAs("muWithTime.pdf");


  TH2F *dummy = new TH2F("dummy","",4,0.,30.,10,0.,1.6);
  dummy->SetStats(0);


  //gStyle_->SetPadTickY(1);

  Int_t ci;   // for color index setting
  ci = TColor::GetColor("#00ff00");
  dummy->SetFillColor(ci);

  dummy->GetXaxis()->SetTitle("L (fb^{-1})");
  dummy->GetXaxis()->SetNdivisions(510);
  dummy->GetXaxis()->SetLabelFont(42);
  dummy->GetXaxis()->SetLabelSize(0.045);
  dummy->GetXaxis()->SetTitleSize(0.045);
  dummy->GetXaxis()->SetTitleOffset(0.95);
  dummy->GetXaxis()->SetTitleFont(42);
  dummy->GetYaxis()->SetNdivisions(510);
  dummy->GetYaxis()->SetTitle("Abs. err. on signal strength (#sigma_{#mu})");
//   dummy->GetYaxis()->SetBinLabel(1,"H#rightarrowWW");
//   dummy->GetYaxis()->SetBinLabel(2,"H#rightarrowZZ");
//   dummy->GetYaxis()->SetBinLabel(3,"H#rightarrow#gamma#gamma");
  dummy->GetYaxis()->SetLabelSize(0.045);
  dummy->GetYaxis()->SetTitleSize(0.045);
  dummy->GetYaxis()->SetTitleOffset(1.2);
  dummy->GetYaxis()->SetTitleFont(42);
  dummy->GetZaxis()->SetLabelFont(42);
  dummy->GetZaxis()->SetLabelSize(0.035);
  dummy->GetZaxis()->SetTitleSize(0.035);
  dummy->GetZaxis()->SetTitleFont(42);
  dummy->Draw("");


//   TLine *line = new TLine(0,1,30,1);
//   line->SetLineColor(kBlue);
//   line->SetLineWidth(2);
//   line->SetLineStyle(2);
//   line->Draw();


//   mu_errAvg_CMS_MVA_graph->Fit(&errVsLumi,"0R+","",0.1,30.);
//   mu_errAvg_CMS_CUT_graph->Fit(&errVsLumi,"0R+","",0.1,30.);
//   mu_errAvg_ATLAS_graph->Fit(&errVsLumi,"0R+","",0.1,30.);


  mu_errAvg_CMS_MVA_lumiScaled.Draw("SAME");
  mu_errAvg_CMS_CUT_lumiScaled.Draw("SAME");
  mu_errAvg_ATLAS_lumiScaled.Draw("SAME");

  mu_errAvg_CMS_MVA_graph->Draw("PSAME");
  mu_errAvg_CMS_CUT_graph->Draw("PSAME");
  mu_errAvg_ATLAS_graph->Draw("PSAME");

//   mu_errAvg_CMS_MVA_graph->GetFunction("errVsLumi")->Draw("SAME");
//   mu_errAvg_CMS_CUT_graph->GetFunction("errVsLumi")->Draw("SAME");
//   mu_errAvg_ATLAS_graph->GetFunction("errVsLumi")->Draw("SAME");

  TLegend a(0.65,0.55,0.9,0.88);
  a.SetFillColor(0);
  a.SetBorderSize(0);
  a.AddEntry(mu_errAvg_CMS_MVA_graph,"CMS MVA Obs. #sigma_{#mu}","PL");
  a.AddEntry(mu_errAvg_CMS_CUT_graph,"CMS CUT Obs. #sigma_{#mu}","PL");
  a.AddEntry(mu_errAvg_ATLAS_graph,"ATLAS Obs. #sigma_{#mu}","PL");

  a.AddEntry(&mu_errAvg_CMS_MVA_lumiScaled,"#frac{1.343}{#sqrt{L}}","L");
  a.AddEntry(&mu_errAvg_CMS_CUT_lumiScaled,"#frac{1.542}{#sqrt{L}}","L");
  a.AddEntry(&mu_errAvg_ATLAS_lumiScaled,"#frac{1.616}{#sqrt{L}}","L");

  a.Draw();


  TLatex *   tex_m=new TLatex();
  tex_m->SetNDC();
//   tex_m->SetTextAngle(90);
  tex_m->SetTextAlign(12);
  tex_m->SetTextSize(0.02);
  tex_m->SetLineWidth(2);
  tex_m->DrawLatex(0.27-0.015,0.47+0.02+.06,"#splitline{CMS-PAS-HIG-11-033}{CMS-PAS-HIG-12-001}");
//   tex_m->DrawLatex(0.27-0.025,0.47-0.2,"");
  tex_m->DrawLatex(0.27-0.015,0.47-0.01+0.06,"ATLAS-CONF-2011-161");

  tex_m->DrawLatex(0.435-0.05,0.47-0.12+0.04,"#splitline{CMS-PAS-HIG-12-015}{ATLAS-CONF-2012-091}");

  tex_m->DrawLatex(0.62-0.1,0.47-0.17+0.04,"ATLAS-CONF-2012-168");

  tex_m->DrawLatex(0.82-0.09,0.47-0.2+0.04,"#splitline{CMS-PAS-HIG-13-001}{ATLAS-CONF-2013-012}");
//   tex_m->DrawLatex(0.82+0.035,0.47-0.15,"");

  tex_m->SetTextAngle(0);
  tex_m->DrawLatex(0.23-.005,0.25+0.04+0.04,"Moriond 2012");
  tex_m->DrawLatex(0.4-0.01,0.23+0.005+0.04,"ICHEP 2012");
  tex_m->DrawLatex(0.77,0.17+0.01+0.03,"Moriond 2013");

  Plots->SaveAs("muErrWithTime.png");
  Plots->SaveAs("muErrWithTime.pdf");

}
