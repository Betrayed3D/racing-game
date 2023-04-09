#include "stdafx.h"
#include "MyGame.h"

CMyGame::CMyGame(void)
{
	m_pCar = NULL;
}

CMyGame::~CMyGame(void)
{
	// TODO: add destruction code here
}

/////////////////////////////////////////////////////
// Per-Frame Callback Funtions (must be implemented!)

void CMyGame::OnUpdate()
{
	if (m_pCar) m_pCar->Update(GetTime());
}

void CMyGame::OnDraw(CGraphics* g)
{
	if (m_pCar) m_pCar->Draw(g);
}

/////////////////////////////////////////////////////
// Game Life Cycle

// one time initialisation
void CMyGame::OnInitialize()
{
}

// called at the start of a new game - display menu here
void CMyGame::OnDisplayMenu()
{
	if (m_pCar) delete m_pCar;
	m_pCar = new CSpriteCar(50, 50, GetTime());
	StartGame();
}

// called when Game Mode entered
void CMyGame::OnStartGame()
{
}

// called when Game is Over
void CMyGame::OnGameOver()
{
}

// one time termination code
void CMyGame::OnTerminate()
{
}

/////////////////////////////////////////////////////
// Keyboard Event Handlers

void CMyGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	if (sym == SDLK_F4 && (mod & (KMOD_LALT | KMOD_RALT)))
		StopGame();
	if (sym == SDLK_F2)
		NewGame();

	// Steer the car
	if (!m_pCar) return;
	if (sym == SDLK_RIGHT)
		m_pCar->Turn(1);
	if (sym == SDLK_LEFT)
		m_pCar->Turn(-1);
	if (sym == SDLK_UP)
		m_pCar->SetGear(1);
	if (sym == SDLK_DOWN)
		m_pCar->SetGear(-1);
	if (sym == SDLK_SPACE)
		m_pCar->SetBrake(true);
}

void CMyGame::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	if (sym == SDLK_RIGHT || sym == SDLK_LEFT)
		m_pCar->Turn(0);
	if (sym == SDLK_UP || sym == SDLK_DOWN)
		m_pCar->SetGear(0);
	if (sym == SDLK_SPACE)
		m_pCar->SetBrake(false);
}

/////////////////////////////////////////////////////
// Mouse Events Handlers

void CMyGame::OnMouseMove(Uint16 x,Uint16 y,Sint16 relx,Sint16 rely,bool bLeft,bool bRight,bool bMiddle)
{
}

void CMyGame::OnLButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnLButtonUp(Uint16 x,Uint16 y)
{
}

void CMyGame::OnRButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnRButtonUp(Uint16 x,Uint16 y)
{
}

void CMyGame::OnMButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnMButtonUp(Uint16 x,Uint16 y)
{
}
