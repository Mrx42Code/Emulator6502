/**********************************************************************************
* MIT License																	  *
*																				  *
* Copyright(c) 2021 Mrx42Code                                                     *
* https://github.com/Mrx42Code                          				          *
*																				  *
* Permission is hereby granted, free of charge, to any person obtaining a copy    *
* of this softwareand associated documentation files(the "Software"), to deal	  *
* in the Software without restriction, including without limitation the rights	  *
* to use, copy, modify, merge, publish, distribute, sublicense, and /or sell	  *
* copies of the Software, and to permit persons to whom the Software is			  *
* furnished to do so, subject to the following conditions :						  *
*																				  *
* The above copyright noticeand this permission notice shall be included in all   *
* copies or substantial portions of the Software.								  *
*																				  *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR	  *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,		  *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE	  *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER		  *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   *
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE	  *
* SOFTWARE.																		  *
 **********************************************************************************/

 //-----------------------------------------------------------------------------
 // File: Emulator6502.cpp: Defines the entry point for the application.
 //-----------------------------------------------------------------------------
#include "Emulator6502.h"
#include "MC_Hardware6502.h"

using namespace std;

//*****************************************************************************  
// Public Code
//*****************************************************************************

//-----------------------------------------------------------------------------
// IMPLEMENT_DYNCREATE
//-----------------------------------------------------------------------------
extern MC_Hardware6502 mc_Hardware6502;
//-----------------------------------------------------------------------------
// message handlers
//-----------------------------------------------------------------------------

//-Public----------------------------------------------------------------------
// Name:   main()
//-----------------------------------------------------------------------------
int main()
{
    HANDLE hConsole;
    DWORD mode;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    if (GetConsoleMode(hConsole, &mode)) {
        if (!(mode & ENABLE_VIRTUAL_TERMINAL_PROCESSING)) {
            mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hConsole, mode);
        }
    }
    mc_Hardware6502.Initialize();
    mc_Hardware6502.Create();
    mc_Hardware6502.CpuSetParameters();
    mc_Hardware6502.CpuMainLoop();
    mc_Hardware6502.Destroy();
    mc_Hardware6502.PrintStatus(false, "App Ends");
    return 0;
}














//*****************************************************************************  
// Protected Code
//*****************************************************************************

//-Protected-------------------------------------------------------------------
// Name: 
//-----------------------------------------------------------------------------

