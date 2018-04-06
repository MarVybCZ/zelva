# Microsoft Developer Studio Generated NMAKE File, Based on InterCom.dsp
!IF "$(CFG)" == ""
CFG=InterCom - Win32 Debug
!MESSAGE No configuration specified. Defaulting to InterCom - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "InterCom - Win32 Debug" && "$(CFG)" != "InterCom - Win32 Unicode Debug" && "$(CFG)" != "InterCom - Win32 Release MinSize" && "$(CFG)" != "InterCom - Win32 Release MinDependency" && "$(CFG)" != "InterCom - Win32 Unicode Release MinSize" && "$(CFG)" != "InterCom - Win32 Unicode Release MinDependency"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "InterCom.mak" CFG="InterCom - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "InterCom - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InterCom - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InterCom - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InterCom - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InterCom - Win32 Unicode Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InterCom - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "InterCom - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\InterCom.dll" "$(OUTDIR)\InterCom.bsc" ".\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Expression.obj"
	-@erase "$(INTDIR)\Expression.sbr"
	-@erase "$(INTDIR)\InterCom.obj"
	-@erase "$(INTDIR)\InterCom.pch"
	-@erase "$(INTDIR)\InterCom.res"
	-@erase "$(INTDIR)\InterCom.sbr"
	-@erase "$(INTDIR)\Interface.obj"
	-@erase "$(INTDIR)\Interface.sbr"
	-@erase "$(INTDIR)\Interpret.obj"
	-@erase "$(INTDIR)\Interpret.sbr"
	-@erase "$(INTDIR)\Krok.obj"
	-@erase "$(INTDIR)\Krok.sbr"
	-@erase "$(INTDIR)\Library.obj"
	-@erase "$(INTDIR)\Library.sbr"
	-@erase "$(INTDIR)\mapa.obj"
	-@erase "$(INTDIR)\mapa.sbr"
	-@erase "$(INTDIR)\Parametrs.obj"
	-@erase "$(INTDIR)\Parametrs.sbr"
	-@erase "$(INTDIR)\Presun.obj"
	-@erase "$(INTDIR)\Presun.sbr"
	-@erase "$(INTDIR)\Prikazy.obj"
	-@erase "$(INTDIR)\Prikazy.sbr"
	-@erase "$(INTDIR)\Prvek.obj"
	-@erase "$(INTDIR)\Prvek.sbr"
	-@erase "$(INTDIR)\Rotace.obj"
	-@erase "$(INTDIR)\Rotace.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\TurBlok.obj"
	-@erase "$(INTDIR)\TurBlok.sbr"
	-@erase "$(INTDIR)\Turtle.obj"
	-@erase "$(INTDIR)\Turtle.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\InterCom.bsc"
	-@erase "$(OUTDIR)\InterCom.dll"
	-@erase "$(OUTDIR)\InterCom.exp"
	-@erase "$(OUTDIR)\InterCom.ilk"
	-@erase "$(OUTDIR)\InterCom.lib"
	-@erase "$(OUTDIR)\InterCom.pdb"
	-@erase ".\InterCom.h"
	-@erase ".\InterCom.tlb"
	-@erase ".\InterCom_i.c"
	-@erase ".\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\InterCom.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x405 /fo"$(INTDIR)\InterCom.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\InterCom.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Expression.sbr" \
	"$(INTDIR)\InterCom.sbr" \
	"$(INTDIR)\Interface.sbr" \
	"$(INTDIR)\Interpret.sbr" \
	"$(INTDIR)\Krok.sbr" \
	"$(INTDIR)\Library.sbr" \
	"$(INTDIR)\mapa.sbr" \
	"$(INTDIR)\Parametrs.sbr" \
	"$(INTDIR)\Presun.sbr" \
	"$(INTDIR)\Prikazy.sbr" \
	"$(INTDIR)\Prvek.sbr" \
	"$(INTDIR)\Rotace.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\TurBlok.sbr" \
	"$(INTDIR)\Turtle.sbr"

"$(OUTDIR)\InterCom.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\InterCom.pdb" /debug /machine:I386 /nodefaultlib:"LIBCD" /def:".\InterCom.def" /out:"$(OUTDIR)\InterCom.dll" /implib:"$(OUTDIR)\InterCom.lib" /pdbtype:sept 
DEF_FILE= \
	".\InterCom.def"
LINK32_OBJS= \
	"$(INTDIR)\Expression.obj" \
	"$(INTDIR)\InterCom.obj" \
	"$(INTDIR)\Interface.obj" \
	"$(INTDIR)\Interpret.obj" \
	"$(INTDIR)\Krok.obj" \
	"$(INTDIR)\Library.obj" \
	"$(INTDIR)\mapa.obj" \
	"$(INTDIR)\Parametrs.obj" \
	"$(INTDIR)\Presun.obj" \
	"$(INTDIR)\Prikazy.obj" \
	"$(INTDIR)\Prvek.obj" \
	"$(INTDIR)\Rotace.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TurBlok.obj" \
	"$(INTDIR)\Turtle.obj" \
	"$(INTDIR)\InterCom.res"

"$(OUTDIR)\InterCom.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\InterCom.dll
InputPath=.\Debug\InterCom.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\InterCom.dll" ".\InterCom.tlb" ".\InterCom.h" ".\InterCom_i.c" ".\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Expression.obj"
	-@erase "$(INTDIR)\InterCom.obj"
	-@erase "$(INTDIR)\InterCom.pch"
	-@erase "$(INTDIR)\InterCom.res"
	-@erase "$(INTDIR)\Interface.obj"
	-@erase "$(INTDIR)\Interpret.obj"
	-@erase "$(INTDIR)\Krok.obj"
	-@erase "$(INTDIR)\Library.obj"
	-@erase "$(INTDIR)\mapa.obj"
	-@erase "$(INTDIR)\Parametrs.obj"
	-@erase "$(INTDIR)\Presun.obj"
	-@erase "$(INTDIR)\Prikazy.obj"
	-@erase "$(INTDIR)\Prvek.obj"
	-@erase "$(INTDIR)\Rotace.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TurBlok.obj"
	-@erase "$(INTDIR)\Turtle.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\InterCom.dll"
	-@erase "$(OUTDIR)\InterCom.exp"
	-@erase "$(OUTDIR)\InterCom.ilk"
	-@erase "$(OUTDIR)\InterCom.lib"
	-@erase "$(OUTDIR)\InterCom.pdb"
	-@erase ".\InterCom.h"
	-@erase ".\InterCom.tlb"
	-@erase ".\InterCom_i.c"
	-@erase ".\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\InterCom.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x405 /fo"$(INTDIR)\InterCom.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\InterCom.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\InterCom.pdb" /debug /machine:I386 /def:".\InterCom.def" /out:"$(OUTDIR)\InterCom.dll" /implib:"$(OUTDIR)\InterCom.lib" /pdbtype:sept 
DEF_FILE= \
	".\InterCom.def"
LINK32_OBJS= \
	"$(INTDIR)\Expression.obj" \
	"$(INTDIR)\InterCom.obj" \
	"$(INTDIR)\Interface.obj" \
	"$(INTDIR)\Interpret.obj" \
	"$(INTDIR)\Krok.obj" \
	"$(INTDIR)\Library.obj" \
	"$(INTDIR)\mapa.obj" \
	"$(INTDIR)\Parametrs.obj" \
	"$(INTDIR)\Presun.obj" \
	"$(INTDIR)\Prikazy.obj" \
	"$(INTDIR)\Prvek.obj" \
	"$(INTDIR)\Rotace.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TurBlok.obj" \
	"$(INTDIR)\Turtle.obj" \
	"$(INTDIR)\InterCom.res"

"$(OUTDIR)\InterCom.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\InterCom.dll
InputPath=.\DebugU\InterCom.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode DLL on Windows 95 
	:end 
<< 
	

!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"

OUTDIR=.\ReleaseMinSize
INTDIR=.\ReleaseMinSize
# Begin Custom Macros
OutDir=.\ReleaseMinSize
# End Custom Macros

ALL : "$(OUTDIR)\InterCom.dll" ".\InterCom.tlb" ".\InterCom.h" ".\InterCom_i.c" ".\ReleaseMinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Expression.obj"
	-@erase "$(INTDIR)\InterCom.obj"
	-@erase "$(INTDIR)\InterCom.pch"
	-@erase "$(INTDIR)\InterCom.res"
	-@erase "$(INTDIR)\Interface.obj"
	-@erase "$(INTDIR)\Interpret.obj"
	-@erase "$(INTDIR)\Krok.obj"
	-@erase "$(INTDIR)\Library.obj"
	-@erase "$(INTDIR)\mapa.obj"
	-@erase "$(INTDIR)\Parametrs.obj"
	-@erase "$(INTDIR)\Presun.obj"
	-@erase "$(INTDIR)\Prikazy.obj"
	-@erase "$(INTDIR)\Prvek.obj"
	-@erase "$(INTDIR)\Rotace.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TurBlok.obj"
	-@erase "$(INTDIR)\Turtle.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\InterCom.dll"
	-@erase "$(OUTDIR)\InterCom.exp"
	-@erase "$(OUTDIR)\InterCom.lib"
	-@erase ".\InterCom.h"
	-@erase ".\InterCom.tlb"
	-@erase ".\InterCom_i.c"
	-@erase ".\ReleaseMinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /Fp"$(INTDIR)\InterCom.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x405 /fo"$(INTDIR)\InterCom.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\InterCom.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\InterCom.pdb" /machine:I386 /def:".\InterCom.def" /out:"$(OUTDIR)\InterCom.dll" /implib:"$(OUTDIR)\InterCom.lib" 
DEF_FILE= \
	".\InterCom.def"
LINK32_OBJS= \
	"$(INTDIR)\Expression.obj" \
	"$(INTDIR)\InterCom.obj" \
	"$(INTDIR)\Interface.obj" \
	"$(INTDIR)\Interpret.obj" \
	"$(INTDIR)\Krok.obj" \
	"$(INTDIR)\Library.obj" \
	"$(INTDIR)\mapa.obj" \
	"$(INTDIR)\Parametrs.obj" \
	"$(INTDIR)\Presun.obj" \
	"$(INTDIR)\Prikazy.obj" \
	"$(INTDIR)\Prvek.obj" \
	"$(INTDIR)\Rotace.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TurBlok.obj" \
	"$(INTDIR)\Turtle.obj" \
	"$(INTDIR)\InterCom.res"

"$(OUTDIR)\InterCom.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\InterCom.dll
InputPath=.\ReleaseMinSize\InterCom.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"

OUTDIR=.\ReleaseMinDependency
INTDIR=.\ReleaseMinDependency
# Begin Custom Macros
OutDir=.\ReleaseMinDependency
# End Custom Macros

ALL : "$(OUTDIR)\InterCom.dll" ".\InterCom.tlb" ".\InterCom.h" ".\InterCom_i.c" ".\ReleaseMinDependency\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Expression.obj"
	-@erase "$(INTDIR)\InterCom.obj"
	-@erase "$(INTDIR)\InterCom.pch"
	-@erase "$(INTDIR)\InterCom.res"
	-@erase "$(INTDIR)\Interface.obj"
	-@erase "$(INTDIR)\Interpret.obj"
	-@erase "$(INTDIR)\Krok.obj"
	-@erase "$(INTDIR)\Library.obj"
	-@erase "$(INTDIR)\mapa.obj"
	-@erase "$(INTDIR)\Parametrs.obj"
	-@erase "$(INTDIR)\Presun.obj"
	-@erase "$(INTDIR)\Prikazy.obj"
	-@erase "$(INTDIR)\Prvek.obj"
	-@erase "$(INTDIR)\Rotace.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TurBlok.obj"
	-@erase "$(INTDIR)\Turtle.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\InterCom.dll"
	-@erase "$(OUTDIR)\InterCom.exp"
	-@erase "$(OUTDIR)\InterCom.lib"
	-@erase ".\InterCom.h"
	-@erase ".\InterCom.tlb"
	-@erase ".\InterCom_i.c"
	-@erase ".\ReleaseMinDependency\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\InterCom.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x405 /fo"$(INTDIR)\InterCom.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\InterCom.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\InterCom.pdb" /machine:I386 /def:".\InterCom.def" /out:"$(OUTDIR)\InterCom.dll" /implib:"$(OUTDIR)\InterCom.lib" 
DEF_FILE= \
	".\InterCom.def"
LINK32_OBJS= \
	"$(INTDIR)\Expression.obj" \
	"$(INTDIR)\InterCom.obj" \
	"$(INTDIR)\Interface.obj" \
	"$(INTDIR)\Interpret.obj" \
	"$(INTDIR)\Krok.obj" \
	"$(INTDIR)\Library.obj" \
	"$(INTDIR)\mapa.obj" \
	"$(INTDIR)\Parametrs.obj" \
	"$(INTDIR)\Presun.obj" \
	"$(INTDIR)\Prikazy.obj" \
	"$(INTDIR)\Prvek.obj" \
	"$(INTDIR)\Rotace.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TurBlok.obj" \
	"$(INTDIR)\Turtle.obj" \
	"$(INTDIR)\InterCom.res"

"$(OUTDIR)\InterCom.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\InterCom.dll
InputPath=.\ReleaseMinDependency\InterCom.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"

OUTDIR=.\ReleaseUMinSize
INTDIR=.\ReleaseUMinSize
# Begin Custom Macros
OutDir=.\ReleaseUMinSize
# End Custom Macros

ALL : "$(OUTDIR)\InterCom.dll" ".\InterCom.tlb" ".\InterCom.h" ".\InterCom_i.c" ".\ReleaseUMinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Expression.obj"
	-@erase "$(INTDIR)\InterCom.obj"
	-@erase "$(INTDIR)\InterCom.pch"
	-@erase "$(INTDIR)\InterCom.res"
	-@erase "$(INTDIR)\Interface.obj"
	-@erase "$(INTDIR)\Interpret.obj"
	-@erase "$(INTDIR)\Krok.obj"
	-@erase "$(INTDIR)\Library.obj"
	-@erase "$(INTDIR)\mapa.obj"
	-@erase "$(INTDIR)\Parametrs.obj"
	-@erase "$(INTDIR)\Presun.obj"
	-@erase "$(INTDIR)\Prikazy.obj"
	-@erase "$(INTDIR)\Prvek.obj"
	-@erase "$(INTDIR)\Rotace.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TurBlok.obj"
	-@erase "$(INTDIR)\Turtle.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\InterCom.dll"
	-@erase "$(OUTDIR)\InterCom.exp"
	-@erase "$(OUTDIR)\InterCom.lib"
	-@erase ".\InterCom.h"
	-@erase ".\InterCom.tlb"
	-@erase ".\InterCom_i.c"
	-@erase ".\ReleaseUMinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /Fp"$(INTDIR)\InterCom.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x405 /fo"$(INTDIR)\InterCom.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\InterCom.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\InterCom.pdb" /machine:I386 /def:".\InterCom.def" /out:"$(OUTDIR)\InterCom.dll" /implib:"$(OUTDIR)\InterCom.lib" 
DEF_FILE= \
	".\InterCom.def"
LINK32_OBJS= \
	"$(INTDIR)\Expression.obj" \
	"$(INTDIR)\InterCom.obj" \
	"$(INTDIR)\Interface.obj" \
	"$(INTDIR)\Interpret.obj" \
	"$(INTDIR)\Krok.obj" \
	"$(INTDIR)\Library.obj" \
	"$(INTDIR)\mapa.obj" \
	"$(INTDIR)\Parametrs.obj" \
	"$(INTDIR)\Presun.obj" \
	"$(INTDIR)\Prikazy.obj" \
	"$(INTDIR)\Prvek.obj" \
	"$(INTDIR)\Rotace.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TurBlok.obj" \
	"$(INTDIR)\Turtle.obj" \
	"$(INTDIR)\InterCom.res"

"$(OUTDIR)\InterCom.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\InterCom.dll
InputPath=.\ReleaseUMinSize\InterCom.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode DLL on Windows 95 
	:end 
<< 
	

!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"

OUTDIR=.\ReleaseUMinDependency
INTDIR=.\ReleaseUMinDependency
# Begin Custom Macros
OutDir=.\ReleaseUMinDependency
# End Custom Macros

ALL : "$(OUTDIR)\InterCom.dll" ".\InterCom.tlb" ".\InterCom.h" ".\InterCom_i.c" ".\ReleaseUMinDependency\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Expression.obj"
	-@erase "$(INTDIR)\InterCom.obj"
	-@erase "$(INTDIR)\InterCom.pch"
	-@erase "$(INTDIR)\InterCom.res"
	-@erase "$(INTDIR)\Interface.obj"
	-@erase "$(INTDIR)\Interpret.obj"
	-@erase "$(INTDIR)\Krok.obj"
	-@erase "$(INTDIR)\Library.obj"
	-@erase "$(INTDIR)\mapa.obj"
	-@erase "$(INTDIR)\Parametrs.obj"
	-@erase "$(INTDIR)\Presun.obj"
	-@erase "$(INTDIR)\Prikazy.obj"
	-@erase "$(INTDIR)\Prvek.obj"
	-@erase "$(INTDIR)\Rotace.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TurBlok.obj"
	-@erase "$(INTDIR)\Turtle.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\InterCom.dll"
	-@erase "$(OUTDIR)\InterCom.exp"
	-@erase "$(OUTDIR)\InterCom.lib"
	-@erase ".\InterCom.h"
	-@erase ".\InterCom.tlb"
	-@erase ".\InterCom_i.c"
	-@erase ".\ReleaseUMinDependency\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\InterCom.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x405 /fo"$(INTDIR)\InterCom.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\InterCom.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\InterCom.pdb" /machine:I386 /def:".\InterCom.def" /out:"$(OUTDIR)\InterCom.dll" /implib:"$(OUTDIR)\InterCom.lib" 
DEF_FILE= \
	".\InterCom.def"
LINK32_OBJS= \
	"$(INTDIR)\Expression.obj" \
	"$(INTDIR)\InterCom.obj" \
	"$(INTDIR)\Interface.obj" \
	"$(INTDIR)\Interpret.obj" \
	"$(INTDIR)\Krok.obj" \
	"$(INTDIR)\Library.obj" \
	"$(INTDIR)\mapa.obj" \
	"$(INTDIR)\Parametrs.obj" \
	"$(INTDIR)\Presun.obj" \
	"$(INTDIR)\Prikazy.obj" \
	"$(INTDIR)\Prvek.obj" \
	"$(INTDIR)\Rotace.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TurBlok.obj" \
	"$(INTDIR)\Turtle.obj" \
	"$(INTDIR)\InterCom.res"

"$(OUTDIR)\InterCom.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\InterCom.dll
InputPath=.\ReleaseUMinDependency\InterCom.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode DLL on Windows 95 
	:end 
<< 
	

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("InterCom.dep")
!INCLUDE "InterCom.dep"
!ELSE 
!MESSAGE Warning: cannot find "InterCom.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "InterCom - Win32 Debug" || "$(CFG)" == "InterCom - Win32 Unicode Debug" || "$(CFG)" == "InterCom - Win32 Release MinSize" || "$(CFG)" == "InterCom - Win32 Release MinDependency" || "$(CFG)" == "InterCom - Win32 Unicode Release MinSize" || "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"
SOURCE=.\Expression.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"


"$(INTDIR)\Expression.obj"	"$(INTDIR)\Expression.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"


"$(INTDIR)\Expression.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"


"$(INTDIR)\Expression.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"


"$(INTDIR)\Expression.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"


"$(INTDIR)\Expression.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"


"$(INTDIR)\Expression.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ENDIF 

SOURCE=.\InterCom.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"


"$(INTDIR)\InterCom.obj"	"$(INTDIR)\InterCom.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch" ".\InterCom.h" ".\InterCom_i.c"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"


"$(INTDIR)\InterCom.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"


"$(INTDIR)\InterCom.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"


"$(INTDIR)\InterCom.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"


"$(INTDIR)\InterCom.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"


"$(INTDIR)\InterCom.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ENDIF 

SOURCE=.\InterCom.idl

!IF  "$(CFG)" == "InterCom - Win32 Debug"

MTL_SWITCHES=/tlb ".\InterCom.tlb" /h "InterCom.h" /iid "InterCom_i.c" /Oicf 

".\InterCom.tlb"	".\InterCom.h"	".\InterCom_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"

MTL_SWITCHES=/tlb ".\InterCom.tlb" /h "InterCom.h" /iid "InterCom_i.c" /Oicf 

".\InterCom.tlb"	".\InterCom.h"	".\InterCom_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"

MTL_SWITCHES=/tlb ".\InterCom.tlb" /h "InterCom.h" /iid "InterCom_i.c" /Oicf 

".\InterCom.tlb"	".\InterCom.h"	".\InterCom_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"

MTL_SWITCHES=/tlb ".\InterCom.tlb" /h "InterCom.h" /iid "InterCom_i.c" /Oicf 

".\InterCom.tlb"	".\InterCom.h"	".\InterCom_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"

MTL_SWITCHES=/tlb ".\InterCom.tlb" /h "InterCom.h" /iid "InterCom_i.c" /Oicf 

".\InterCom.tlb"	".\InterCom.h"	".\InterCom_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"

MTL_SWITCHES=/tlb ".\InterCom.tlb" /h "InterCom.h" /iid "InterCom_i.c" /Oicf 

".\InterCom.tlb"	".\InterCom.h"	".\InterCom_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\InterCom.rc

"$(INTDIR)\InterCom.res" : $(SOURCE) "$(INTDIR)" ".\InterCom.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Interface.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"


"$(INTDIR)\Interface.obj"	"$(INTDIR)\Interface.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch" ".\InterCom.h"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"


"$(INTDIR)\Interface.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"


"$(INTDIR)\Interface.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"


"$(INTDIR)\Interface.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"


"$(INTDIR)\Interface.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"


"$(INTDIR)\Interface.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ENDIF 

SOURCE=.\Interpret.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"


"$(INTDIR)\Interpret.obj"	"$(INTDIR)\Interpret.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"


"$(INTDIR)\Interpret.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"


"$(INTDIR)\Interpret.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"


"$(INTDIR)\Interpret.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"


"$(INTDIR)\Interpret.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"


"$(INTDIR)\Interpret.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ENDIF 

SOURCE=.\Krok.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"


"$(INTDIR)\Krok.obj"	"$(INTDIR)\Krok.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"


"$(INTDIR)\Krok.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"


"$(INTDIR)\Krok.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"


"$(INTDIR)\Krok.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"


"$(INTDIR)\Krok.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"


"$(INTDIR)\Krok.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ENDIF 

SOURCE=.\Library.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"


"$(INTDIR)\Library.obj"	"$(INTDIR)\Library.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"


"$(INTDIR)\Library.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"


"$(INTDIR)\Library.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"


"$(INTDIR)\Library.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"


"$(INTDIR)\Library.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"


"$(INTDIR)\Library.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ENDIF 

SOURCE=.\mapa.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"


"$(INTDIR)\mapa.obj"	"$(INTDIR)\mapa.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"


"$(INTDIR)\mapa.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"


"$(INTDIR)\mapa.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"


"$(INTDIR)\mapa.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"


"$(INTDIR)\mapa.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"


"$(INTDIR)\mapa.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ENDIF 

SOURCE=.\Parametrs.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"


"$(INTDIR)\Parametrs.obj"	"$(INTDIR)\Parametrs.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"


"$(INTDIR)\Parametrs.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"


"$(INTDIR)\Parametrs.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"


"$(INTDIR)\Parametrs.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"


"$(INTDIR)\Parametrs.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"


"$(INTDIR)\Parametrs.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ENDIF 

SOURCE=.\Presun.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"


"$(INTDIR)\Presun.obj"	"$(INTDIR)\Presun.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"


"$(INTDIR)\Presun.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"


"$(INTDIR)\Presun.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"


"$(INTDIR)\Presun.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"


"$(INTDIR)\Presun.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"


"$(INTDIR)\Presun.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ENDIF 

SOURCE=.\Prikazy.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"


"$(INTDIR)\Prikazy.obj"	"$(INTDIR)\Prikazy.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"


"$(INTDIR)\Prikazy.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"


"$(INTDIR)\Prikazy.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"


"$(INTDIR)\Prikazy.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"


"$(INTDIR)\Prikazy.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"


"$(INTDIR)\Prikazy.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ENDIF 

SOURCE=.\Prvek.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"


"$(INTDIR)\Prvek.obj"	"$(INTDIR)\Prvek.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"


"$(INTDIR)\Prvek.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"


"$(INTDIR)\Prvek.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"


"$(INTDIR)\Prvek.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"


"$(INTDIR)\Prvek.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"


"$(INTDIR)\Prvek.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ENDIF 

SOURCE=.\Rotace.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"


"$(INTDIR)\Rotace.obj"	"$(INTDIR)\Rotace.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"


"$(INTDIR)\Rotace.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"


"$(INTDIR)\Rotace.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"


"$(INTDIR)\Rotace.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"


"$(INTDIR)\Rotace.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"


"$(INTDIR)\Rotace.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\InterCom.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\InterCom.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\InterCom.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\InterCom.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"

CPP_SWITCHES=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /Fp"$(INTDIR)\InterCom.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\InterCom.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"

CPP_SWITCHES=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\InterCom.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\InterCom.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"

CPP_SWITCHES=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /Fp"$(INTDIR)\InterCom.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\InterCom.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"

CPP_SWITCHES=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\InterCom.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\InterCom.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TurBlok.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"


"$(INTDIR)\TurBlok.obj"	"$(INTDIR)\TurBlok.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"


"$(INTDIR)\TurBlok.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"


"$(INTDIR)\TurBlok.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"


"$(INTDIR)\TurBlok.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"


"$(INTDIR)\TurBlok.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"


"$(INTDIR)\TurBlok.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ENDIF 

SOURCE=.\Turtle.cpp

!IF  "$(CFG)" == "InterCom - Win32 Debug"


"$(INTDIR)\Turtle.obj"	"$(INTDIR)\Turtle.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Debug"


"$(INTDIR)\Turtle.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinSize"


"$(INTDIR)\Turtle.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Release MinDependency"


"$(INTDIR)\Turtle.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinSize"


"$(INTDIR)\Turtle.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ELSEIF  "$(CFG)" == "InterCom - Win32 Unicode Release MinDependency"


"$(INTDIR)\Turtle.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\InterCom.pch"


!ENDIF 


!ENDIF 

