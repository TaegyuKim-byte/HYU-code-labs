import tkinter

# horses

img_list = ['''

                                                                                        .  Rs
                                                                              .ctSSARRRAAACtRAAAc
                                                                          ,tARRRAASSSSSSASSSSssSAAS
                                                                     .cSARRASSAASSSSSAASSASSARASARRAC
                                    ,cSAAASSSSSSSAAASSSCCCSCC,c,.,CARRRAASSASSSSSSSASSsssARAAASSAASSSS,
                               AASSSssSSSAAASscSSSSAASSSSSSAAAAASsSsASSSSSAAASSssSASASSARRRAAAAAAARRRsssSc
                             SASSSSsSSAAAAAASsSARARAAssSCSSSSARASSSsssASsASssssSAAASSSSAA        ,cSRASAAS
                          ,SARASAAAAAAsSSAAASSASRARAASSSSAASSSSSSSASSSssSsscSSSSSSSSAARs              ,
                          SRSARSRRARASssssSSsARAASSsSSAAAASSscSSSASsSAAccsSsSSScsSAARR
                          ARAAA CRARAAsSSSsSAAASRRAAAAsSSAAASSSSAASSAASSsscSSSSssSAA
                       c SRRAR,  RAAAASSSSSAAASSAARRRSSsSSSSSSAAARARRASASSASSSsSSS
                     cAAARAASSAAASAAAAASSSAARRC,      ARRAARRASsSSAAARRRARAAAASAS
                  ,SSc  SAASAAAAAASSAAAccCc               cARRASSSSAARARRARSSAAS
                       cRAs,  AAR                              ,cRRRRRRAAAssRA
                       cAc    ,RR                                 RRRRRAAAAc
                       sA      ,RA                               RRRRRSAAAS,
                ,ccccccc        SsS                             SASA   SASc
                             ,cccc                             AASc    ,AAc
                             SS,                cRSSscc,  , cRAAA       ASc
                                                                        ,RS
                               , ,,,,, ,  ,,,c,,,,,,,,, , ,, , , ,    , ,cc ,      ,,
     ,,,,,c,cccccccccccccssSSSSSSSSSSSSSSSSSSSAAAAAARARAARARARRRSSsSSAASsc ,cssssssscsSssSSScccccccccccc,,,,, ,
                           ,  , , , , ,, , , ,,,,,,,,,,,,,,, ,, ,,,,, , ,, , ,,,, ,,,    ,
''',
'''

                                                                                          cRSs
                                                                                  .,cARRRAAASSsAA,
                                                                            .cSRRRRRRRRASSSSAAAAAARc
                                          ,,cccc,,cSSccsst,,.         .,csARRRRSSSSAAAAsAARAASAAASSSA
                                     ,sASASSsssscsSSAASSSSAAAAASsc,SARAAAAAASSAAAAAAAsssSAARAAAAAARAASS
                                ,SSSSsSSAAAAASsSAAAAAAAAAAASSAASSAASSSSSAAAASAASSSAAAssARRS  ,,ccsSAASSARc
                              sRASSssAAAAAAASASAASSASSSAAAAAAAAASSAAAASSASASSSSSASSSSSAAs           ,SRc
                           ,AAAASASSAAASsASsSsSASSAAAASSASSSAAASASSRAsSSSSssASSSSAAAAAA
                            sSSRRRRAAAAASSsssSSAAAAAASSAASsSSAAASAsSAAsssssSSsssAAARA
                           cASSARARRARAAASSssSASARRRAAASSSSSASSSSsSRASAsssSSSSSsARS
                           ARRRRRA  RRAAAASSsSSSARRRRRARAAsSSSSssSSSSSSSASSSSSSSc
                       SAARs   ,cSAAAAAASSSAARRR        SRRASASSsRARRRRAAAASARR
                  ,s, ,,     RRAAAARAARRRRsc                ,sARRRRRRAAAAAARRR
                             ,RAs  RRRR                           AASASSRA,
                              cAc    RRRs                        RAARARRR
                              ,AA      ARRS                     RAAARRRR
                                 c       csc,                 SAAs  SRSc
                               css       ccc           cAASc cRA    sSSc
                              ccc        ss,                sARSsScsSc
                             sAc                           ,cc
             ,    , , ,   , ,,c,,,,,,,, ,,,,,,, , , ,,,, ,  ,c, , ,,c,,  ,,,,     , ,   ,
     ,,,,,cccccccccccccscscSSAAASSSSSSSASSSSSSSSSSSSSAAAAARAsssssSSSAAAAASSSSsscssssscsssssscccccccccc,c,,,,,,
                            ,  , , , , , ,, ,,,,,,,,,,,,,, ,,,,,, ,, ,,,,,,, , , , ,  , , ,
''',
'''
                                                                                           ,
                                                                                    ,cSSC  ARAA,
                                                                               ,CRRRRRRAASSCSSSSAS
                                                                           ,cSASSASSSAACASAAAAASARAA
                                           ,csSSAAAACSAASACCsCc,, ...,csSARSSSSSSAAASsCCSAAAAASAAASSA,
                                       ,ASSsSSSSSAAACSCSSSSscCSSAAAARRAASSSSSASSCAAASSSSSAARAAAAARRSSSS,
                                   ,SASsSAAAAASCSCSAAAASSSSSsSSACSASCASAAAASsCsSSSSSSSSSS.        ,AASSAc
                               CAASCSCsSSAAAAAASSSSSsSSSAAAASsSSsSscCCSSAASSSCCSASSSAAA,             ,
                              cAAACACsAAAcSSSASCSssCsSSSAAAAASSCSSSCSSSACsCSASCsSAAAAC
                             sAAAAARAARAAASCSSSCSAAsAAAcSSSASSAsAAAsSAAASsSSACCSSARs
                             SsARRRRRRRRRAAAASACSSCRRRRRAssSSCSSAAAAAASAsCSSSSCSAS
                           ,RARRAAAS  ,AARAAAAASSCARSCRAAARRASSScSSSASSSSSSCSSSAR
                    ,, , SRRRS,         RAAAAASSRRR        ,ARAASRRRAAASAASARAS
                   cSAARC,           ,RARARRRRRRC               ,CRRARASAARRc
                                   AAAAARRRRRC                    SASSCSRRRR,
                                   ,RRAARRRRR,                  cAAAAS ,RRRRs
                                     ,RAs,  ,RAsS,             CAAAA,    AASAc
                                         ,,,     ,Ccc         sAAc         CAS
                                          ,,c      cc,      ,RRA          cRc
                                          ,,,      ,C,  ,, cA,,ARASc,,C,
                                         ,CS     CSCCC
                , , , ,  , ,,       ,,,  , ,,,, ,,,,,,,,,,,, ,  , , , , ,               ,, , ,   ,,,,,  ,,,,
     ,,,,,,,,,ccccccccCCcCCssssCcCsSSASSSASSSsCSSSASSSAAAAARRRRRRRRRRARAASsSsCCCCCCCCccccccc,,,,,,,,,,,,,,,,,
                       ,   ,  , , , ,, , ,,,,, ,,, , ,, ,,,, ,,,, ,, ,, ,,,,, , , , , ,    ,  ,
''',
'''
                                                                                         ,S
                                                                                ,cSRRARR,tRSsCsS,
                                                                           ,csSSsSSSSSssCCCsRSSSSS,
                                                .,,..                   ,sAssSssSSssSSCCsSSSSSSSSsSS
                                           cssssSSsSSSSSSsssSss,  .,cCsSSsCstsSSsSSSsssssRRSSsSSSSSssc
                                       ,SSsssSSSssSSASSssSSSSSsSAAAssSSSsssSSSSSSsSSSSSSSSARRRRSRRSCCCss
                                    cSSSssSSSSSSCsSASssSSSSsSssSSsSSSSsSsSSSstCCsssssSSS,         ,sSss,
                                 cSCsSSssSSSSSSsssSCSSSSSSSSAsSSSsSsCssSsSCcssCsSsssSSC
                               ,SSsCSCsSSsCSSSSSCsRSsssSSSssSSSSSCSsCctSSsCsssCcsSSSR
                             ,SsCsSSRSSRRSSssSSSsCCsSASSSASSssssSSssSSSCssCCssCCsSR,
                            ,sCSSSRRSRRRRRRRRRSSSSSssRRRRsSSSsRSSSSASSASSsssCssCSRS
                           SSsSSSSs     SRSRRRSSSSSSRRSRRSSRASssSASSASSCssssCssSRR
                      ,sRRRRRRSt            CRSSSSRRRc      tSRRSSRRSSSSSSSsSRR,
                  ,cRRRRRt                  RRRRSRRRS            ,SRSSSCSRRRRRRc
                                           RRRRRRRC,               SSssS   RRCCsC
                                         RSSSsSRRsC,               RSSs,      ssssC
                                           ,RSsSSCCs,  ,          cSRS,          RSs
                                                 c,,ccsssC,        ssc         , c,
                                                   ,CC   ,Ssc,c ,RRRS,       , ,c
                                                    cc,    RRR             ,C C
                                                    cC,      ,           ,CCS,
           ,       ,,,,   , , ,   , ,,,,,,,,, ,,,,,, ,,,,,,,,,,,,,,,,,,,sRc,c,c,,ct,,,,,t,,,, , ,,,,,, , , ,
     ,,,,,,,,,,,,,ccCCCccCcCCCCCcCsssSSSRSSRSSSSSRSSSSSSSSSRRRRRRRSRSSSsssssCCsCccccc,c,ccc,,,,,,c,,,,,,,,,,,, ,
                     ,    , , , , , ,, , ,, ,,,,, ,, ,,, ,,,, ,, ,,,,,,,, , , , , ,  ,  , ,
''',
'''
                                                                                     ..  ASc,
                                                                               ,SRRRAAAAAAASsssAS
                                                                          .cSARSSSSsSAAsSsSSRAAAARS
                                                    ...             .,cSRRRASSSSsSAASsssSAAASSRSSsSS,
                                             ,ctSAAAAASAASAASsSSAAAASsSSssSAAASSSASsSSSSSAAAASAARAASSs
                                         SASSSAASAAAAASRASsSSAAAAAAAASARAARASASsSStSSsSSSAccSRRARRAsssSs
                                     cAASsSAAAAASAASAAAAASsASSAAASsSsSAAAssASssSAAssSAAS           AAsc
                                  sSAAASAAAAAAAASRASSAASSSAASAAAAASSSsssSsSsSSsASSSAAR
                                ARASAASAAASAAAAAASAAAASSSAAAAAAAAAASSSSsSSssSSscSAAA,
                              AASSSARAARRAAASARAAASSSARAASAAAASAAAAAAASSSAASsSSssRAS
                           cASSAASSSARRRRRRRRRRRRRRAAARRAASsSRRAAASSSARRASSSSSSsSAA
                       sSRRARAsSS,      sRRRRRRRAAASsSRRASAARAAASSAAAAASSSASSSSSAc
                   ,ARRRccSt,                 SRRRRASR      cRRRRAAARAAAAAARRRRR
                 ,tc,.                          RRRAARs           ,sRAAsSsARRRScsss
                                               ,ARRAsss              ARAASc   ,AASSAS,
                                               cARAsSSc               ,RRASc       ,RRS,
                                               cRRRASSs      cccc       sAASc        SRc
                                                     cRSc,,cc   ,Ac   ,,,SRAS         ,c
                                                        cscSAc,                      ,ccc
                                                           ,cccc                     ccS
                                                            cRSssc,                 sss
                     ,,,,c,,,,,,,,,,,,c,c,cccc,ccccccccccccsccccsSs,,cssccccccccccccAcccccccccc,,,,,,,,,,,,,, ,
     ,,,,cccccccccccccscsccsssssssscssSSSSSAAASSSAASSSSSSSAASASRAASSSSSssssccccsccccccccccccccccccccccc,,,,,,,
                           , , , , , ,, ,,,,,,,,, ,,,,,,,,,,,,,,,,,,,,,,, ,,,,, ,, , ,  , ,  ,
''',
'''
                                                                                   ..,    Ac
                                                                            .cARRAAASAAASSSSsCCSc
                                                                         ,cSSSsSsSSSSSsCsCssRSSSSS,
                                                     ...             ,sAAAASSSSSSSSSsssCsSSsSsSSssSs
                                              .,,cSSSSSSSSSSSAssSSSSSSSsSSASSSSSSSSSsSsCCsSSSsSSRSSss
                                          CSsSSssSSSSSSSsSSsSSASSSSSSSSSssSssSSsSsStssSSSRccRRRSRRSCCcs
                                     ,SSSCSSSSSssSSSSSSASSsSCSSSSSSSssSSCsCsSSCSSSsCsRS           ,SSst
                                   ,SSSsCSSSSSSSSSSSRSSSSSsSSSSSsssSscssScCsSsCCCssSR,
                               cRSs cSSsSSSSRSSSSSCSSSRSSSSASsSSASSSssCtssSCCssCCsRR
                            ,sSSSSs SsSSSSCSSSSSSSSSCSSSssSscsSSSSSSSSssCSsssCssCSS
                        ,CsSSSSSsSc, RRRRRRSSSSSSSRSsSRSCtsssssssCsSSSssSCsCCCCssSc
                    sRRRRRSSSSs       RRRRRRRRRRSSSSCCRSSSSSSSssssSSsssSssCssssSS,
                ,CSStctcc,               cRRRRRRSRRSSs,  ,SRRRRRSSSSARSSRSsCSRRRSc
                 c                          sRRRRRRRRSs,          ,,csRRSssSscCssCCC,
                                              RRRRRRRRR,                  cRSSSsCsRsCSRs,
                                               RRRRRSRSs                       ,sSs   ,RRR
                                               SRRRsSRRRSC,                     sRR,    ,c,
                                               cSSRS       csc,,cc,  SccCcc  ,c,          ,,c,
                                                 ,SRs           cSsccc, ,,                  s,,
                                                   css,            ,c,c                      scs
                                                     ,,c                                     ,ss,
        , ,,,,, ,,,,,,,,,,,,,,,,,,c,,c,c,,,ccctct,c,tc,,,Ccc,,cctctcttttttttttttctct,tt,,tt,,,,,,,,,,,,,,,,,,
    , ,,,,,,,,,,,ccccCccccccCcCCCCCCCCCcCcCsssCssCCCCCCsCCsCccCcCsSsCsCsCCCCcccCcccccccccccccc,,,c,,,,,,,,,,, ,
                    ,       , , , , , ,,,,, ,, ,,,,,,,,,,, ,, ,,,,,,,,, ,, ,,, , ,, , ,     ,
''',
          
'''
                                                                                      .   ,
                                                                            .,SARRAAAAARRSSRRsss
                                                                         cSSSSsSSSsSSSssCCCCSsSSss
                                                                      .sASsCsCstcsssCcCCSSSsSsSsSSS,
                                                                 ,cctCCstCsstsASSSSSSSsSSRRSsssSSSsCs
                                           ,,  .,ccSSSSSSssSStCsSsSSsSSSSSSSSSssSSssSSSSSSttRSSSRRCsCC,
                                      cSSssSSSsSssSSSASSsssCsSSSSSssSscsSSSSSsCSSsCsSS           tRsSSS
                                    sSSSCsSSsSsSsSSSSSSSASSsSSSSSSCscssSstCCsssCCsSS,               ,
                                 ,CCSSsCsSSSSSssSSSSSssSscssStsSSSssssssssSSCCsssCc
                           cSsRRRssAtssSSsSRSSSssCSSsCSSSSSsssSssssssSSSSsSssCCsss
                      ,CSSSSSsSsSsSS,cSSSSsSSSSssCssSSSSSSSSsSsctsSSSRSSssCCCCCssS
                 cSRRRRSsssSRSRRRRRRRRRRRRRRRSSSRRSssRRRSSSssCCssSSsSSRSssCCCssSRs
              ,cs,  ,SRt,SS         ,RRRRRRRRSRRRSSCc  SRRRRSSSSASASSSRRSRSssSscCCC,
                                      RRRRRRRRRRRRSSCc         ,,,ttSSstSRRRSSSSSsSsCc
                                       ,RRRRRR,  RRSSs,                           SRRSss,
                                       ,RRRRR,    SRRRs                             cRSSRRS,
                                       CCCCS       SSRS,                           ,,,    S,,
                                     ssCCC           SRRSSs,                      ,,         ,,,
                                     Sss,                ,SSScc,               ,CCC            ,sCC
                                      SSc                   ,c,,,,C,           tCs              cRscc
                                       Cs,                       ,CC,,,        t
       , ,,,,,,,,,,,,,,, ,,,,c,,,,,,,,,,cccc,c,ccctctttctttttttttttttc,ttttc,ctc,tc,,,,,t,c,,,,,,,,,,,,,,
     ,,,,,,,,cccccccccccccccccccCCCCCssCC,cCcCCsCCCCCCCCCCcCsssCssssCcccCcCCsCCcccccCccccccccccc,c,,,,,,,,,,,,
                          , , , , , , , ,, ,,,,,,,,,,,,,,,,,,,,,,, ,,,,,,,, , , ,, , , ,  ,
''',
'''

                                                                           .,SAARRRRRRARRAcRRSs
                                                                        cRAARRRASAASSASSSsssSssSA,
                                                                     .SRRRRSSASSSAAASSSsSAAASAAAARA
                                                                    cSSSSSSSSSSSSSSAASSAARRASSAASSSA
                                                .,ctc,.  .,csSSSttSRASsSSASASAAASASAAAAASSAAASSARASSS
                                      ,SAASSsssSSssASAASSAASSSAARASSASsARRRASASSSSSSSS         csSSSSAR,
                                    SAAASsSASssSSSSSAAAAASSsSAASSSsSssssctSsSSSSsSSA              AAsA
                                 ScSASSsSAAAsSSAARAASASAASAAAASASSAAASSssSSASsSSSSc
                              cASsSASSsSAASSASsSRRAsSssSAASSAAAAAAASSSASSSSAAssssSs
                    cSSSSSAASSASSARSSAAAASASSAAAARRAAASSsSSASSSSSsAsAAASSSSsssSSSA,
             ,cc,SRSSSSSSSARSR,cSARRRRRRAASAASSSSsRRRRRAsstSSSAAScAASASASSSsSSsSRA
            csccAARRRSAAc        ARRRRRRRRRAAAssSs   sRRRRASSSRAAsAASSARRRARASAAAss,
                                 sRRRRRRRARRASsSAc          ,cscsSSAAAAAc,cSARRAAASASSSc
                                 SRRRRRRRcARRRAss                                AAsSSRRAS
                               cSscARR      RRAAs                                   SSASAc
                             SSSSSS,         RAAA,                                    cRAc,
                           ,SSs              cRRRc                                       ,cccc
                           SAS               SAAAS                                       css,c, cc
                          SSc                  ARAc                                      ccs    cAScS
                         ccc                     sAS                                      ,
          ,,,, ,,,,,,,,cc,cccccccccccccscscscscccscScccscccccccscccscsccssssccccscsccc,, ,,c,,,,,,,,,,,,, ,  ,
    , ,,,ccccccccccccccSSSccssssSSsscssSsSSSssSssSSSsccsccccscssssscssssscsccscsccccccsccscccccccccccccccc,,,, ,
                          ,   , , ,, , , ,, ,,,,,,,,, , , ,,,,,,,,,,,,,,,,,,,,, , , , ,  , ,
''',
'''

                                                                            ,csSASRRRRRRt  RS
                                                                        ,tSSSAAARRAASSSRRSSRSSsC
                                                                     ,SARRASSSsSsssSsCCsCCCsSSsSSt
                                                                   ,CSSAASsCsCCCCCccSsCCSRSsSsSsRRS
                                                               .cSSCsssstCcSCsSCSssSCssSRRRSss sSSsCS
                                      ctsSSSSSSsCssSSCCSsstscSSASSSsSssSsCsSSSSsssCsSS,  ,cSSSSSRSCCcC
                                 ,sSSSSSSCCCCCCsSSSsSsSSsssSSSsssCCctSsccCssssssCsSS            RStSSS,
                              cSSsSssCCssSSCCSsSSsSSCsSSSSssSASCtsCtCcCsCsSSCCssss               ,t,,
                            cSRRSsCCCsSSSsSsSSSASSSstCcCsSSsSSsCsSsssSSSSssSSsCcCs,
                         cRRRRSSRSSSSSSsSSCsSSSRSASSsSSSSSSssSsCCsSSSSARSSssCssSsS
             ,tSSSSSSssSSSRS CsSRRSSRRSSSsssSSSRRRRARSAASASSASSSscSsSSARRSSsSSCCsc
             ctctSSst,,       RRRRRSSSRSSSSSSS,  ,tRRRRRRRSSSSSSSCSSRSssSRRSSSSSSCC,
               ,             sRRRRRRSSSSSSSsS,          ,,csSSRRRRRRRRSs,,tRRSSRSsSSsC,
                           ,RsSRRRctRSSSSsSS                                 SRRcCsSSsSSst
                         cSsSSR,   ,SRSsCc                                    ,RRRc    tRRs,
                       ssCCSs      SSSSS                                        tRRR      ,,,,
                     cSSs       csRSSs                                             RRR       c,,
                    cSs         RSSC                                                ,c,        csc,
                   ,,,          ,RS                                                   c c      ,Rscs
               , ,cc             ,SS                                                   ,,,
        , , ,SsCCsC,,,,,,,c,,,,,,,ssS,,,,c,c,cc,,t,tctcttc,ccttttt,ct,,,,,,,,,,,,,,,,,,,,sSs,,,,,,,,,,,,,,, ,
     ,,,,,,c,cccccccccccccccsssssssccccCcCCcCCCCCcCcCcCCcCcCCCcCccCccCcCcCCcCCCcccCccccccccCcccccc,,,,,,,,,,,, ,
                     ,    ,  , , , ,, ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, , , , , , ,  ,  ,
''',
'''

                                                                                    ,ccCsc,  R,
                                                                           ,cCSSCCARRRRRRRRRssRAAc
                                                                        cARAAAsSSSSsSSAAASSSSCCCSSAc
                                                                    .,cSRAASSSSSSSSSSSSCSSSAAAAAAAARS
                                                                ,cCARRRRASSSSsSSSsSSAASsAARAAAASAASCAA,
                                  ,cSSAAASSSSSSSsCCCCCCssCCCcsSSSSCSRASSCCSASSASASSSSSSSAS,CAAAAAARASSSS
                               ,AASSCCCSSSSCCcSSAAACCSASCCsSSSSASSSSSCCCCsCsAASSSSSSSAAA       ,cSCSSsCsS,
                            ,ARRSSCCSSAASASCCSASSSscsSCCcSSAAAAASsSASCcCsSASCSSSSSSSRA              AsSAs
                           RAARRAAAAAAAAAASSCAAASAASAACCSSSSSSASCSASSsSssASSSCCSSSSS
                        ,ARRRR,,AAAAAAAAAsSAARSSSSSSASSCAASSSSSSsSACSAAARSSSAAASCCA,
                    .CAARRRRc  CRARAAASSSCARRRAASASCSSASASSSASSSsSSSSSSRRRAAASSCSSSC
            cSAARSARARRAA      cRAAAAAAAAAARS,  ,cARRRRASAASSSSSSSSAAAAAsARRAAAASCS,
            SRARARARARs,     sARRRAARAASSc             cARRRRRRRSSsSSssAASCARRSAAAASCc,
                        ,SSSSAARAARRAAA,                        ,,,,CssssSc,RRRRRRAASASCs,
                       ,SSCSRAAAAAAc                                          RRRR   CAAAAAs,
                     ,AARCASARARR,                                            cRRRc       RRAC,
                   ,,A,   RAA,                                                  SCS           ,,,,
                 ,,c,    SRC                                                     RA,             ccC,
             ,Cccc      ,AR                                                      ,RA                Ccc
             ,          ,,                                                         c,
         , ,,,    ,,,,,c,,,    ,,,,,,         , , , , , ,  ,     ,                 ,,,
     ,,,,,,,,,,,c,c,cccccCSCSSSSSSsCcCCCccCCCccccCCCSASASAASSSsSAASsCCSSSSAAASCcCccCc,,cCcCccCccCc,,,,,,,,  ,
                            , , , , , , ,,,,,,,, ,,,,,,,,,,,,,,,,,,,,,, ,,,, ,, , , ,  ,    ,
''',
'''

                                                                                            c
                                                                                 .,,,,.,    cRSS
                                                                         ,csARRRRRRRRRRRRRRRSSSSSRA
                                                                      cASAARRRASscSRRRRRSSSSSRRSRSRRs
                                     ,ccccscccc,..c,.     .       ,cSRRRRRSASScSAARSSSSSSRRRRRSRRAASAR
                              ccSSRSSSSSSSSSSSSSsSARSSSRRARRARSSSSSSSRSsSSSARRSSSSSRSSSAAARRRRRSRRRRSSSSs
                           ,RRSASScSSARRRRRSSSAASSScSSSRSAAARSSRSScSSSSSASSRSSSSRRSSSSARAS    cSSSRRASSSRRc
                          SRRRRRSSRRRRRRRRSSSSSSAASSRRARRAASSSSSsSRRScSSSSSSSRSSSSRSRRRc            ARAAR,
                         cRRRRRRRRRSSSSRRAASRRRASCASRAAARRASSARRRSASRRSSSSSSSSSSSSRRR
                         ARRRRRRRRRSSSSSSAARRRRRASASSSSSSASRRRRRRRSSCAASSRSSRSSSSSS
                       cRRRRs  RRRRSSRRSSRRRRSSRRRASCSAASRRRRAARRSSSSSRRRSRRSSSSSS
                  ,sRRR,  cscSRRRRRARSSSSRRRc     ,RRARRRARAARRRRRSSSSRRRRRRSSSRRR
                ,SRR  RRARRRRRRSSSSScASc               csARRRRRRRASSRRSRRRRRRSSSRc
             ,,     sRRRRRRRRS,                               ,ARRRRRRRRRRRRRRRSS,
                  cRRRS  RS                                      RRRRRR,   ARRRRRS,
                 SRc    ,RR                                    RARRRS         SRRRS
        SRRSccSc       cRR                                   SSSS               cRRSc
                  ,RAScSS                                  ,RRR                   ,RAS
                                                          ,AR                       RRS
                                                         cc                           Sc
                                                     ,ccS, ,,,, , , ,      ,       ,   c,,
     ,,,,,,,cccccccccccccccSSSSSAARRASSScSSSARRRASAASSSRASRRRRRRRRRASSSRRRRRAScSSccSScSSSccSccccccccccccc,,,, ,
                              , , , ,, , ,,,,,,,,, ,,,,,,,,,,,,,, ,, , ,, , ,,, , , , , , , ,
''']

def close() :
    global loop
    loop = False
    window.destroy()

window = tkinter.Tk()
window.title("세상에서 가장 무서운 동물.jpg")
window.protocol("WM_DELETE_WINDOW", close)

f1 = tkinter.Frame(window)
f1.pack()

canvas = tkinter.Canvas(f1, width=300, height=100)
t1 = canvas.create_text(150, 100, anchor="s", font=("courier", 3))
canvas.pack()

f2 = tkinter.Frame(window)
f2.pack()

label = tkinter.Label(f2, text=0)
label.grid(row=0, column=0, columnspan=3)

def checkin() :
    # to control the loop by setting global variables
    global interval, fare, onBoard
    interval = 100
    fare = 3800
    onBoard = True
    return None

def checkout() :
    # to control the loop by setting global variables
    global interval, onBoard, fare
    interval = 500
    onBoard = False
    return None
    
tkinter.Button(f2, text="하차", command=checkout).grid(row=1, column=0)
tkinter.Button(f2, text="승차", command=checkin).grid(row=1, column=1)

counter = 0
fare = 0
interval = 500
loop = True
onBoard = False

while loop :
    canvas.itemconfig(t1, text=img_list[counter % 10])
    label["text"] = str(fare)
    canvas.after(interval)
    canvas.update();
    if onBoard :
        if counter % 30 == 0 :
            fare = fare + 100
    counter += 1
