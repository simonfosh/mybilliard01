//----------------------------------------------
// MouseStateSMC_AutoGenerated.cpp
// FSM:       MouseStateSMC_AutoGenerated
// Context:   MouseStateSMC
// Version:   
// Generated: Sunday 08/30/2009 at 02:29:40 EDT
//


static char _versID[]  = "";

#include "MouseStateSMC_AutoGenerated.h"

namespace smc
{

//----------------------------------------------
// Definitions of static state objects

//----------------------------------------------
MouseStateSMC_AutoGeneratedMouseReadyState MouseStateSMC_AutoGenerated::MouseReady;
MouseStateSMC_AutoGeneratedButtonDownState MouseStateSMC_AutoGenerated::ButtonDown;
MouseStateSMC_AutoGeneratedDragState MouseStateSMC_AutoGenerated::Drag;

//----------------------------------------------
// Default Event Functions

//----------------------------------------------

void MouseStateSMC_AutoGeneratedState::captureReleased(MouseStateSMC_AutoGenerated& s)
  { s.FSMError("captureReleased", s.GetState().StateName()); }

void MouseStateSMC_AutoGeneratedState::buttonDown(MouseStateSMC_AutoGenerated& s)
  { s.FSMError("buttonDown", s.GetState().StateName()); }

void MouseStateSMC_AutoGeneratedState::buttonUp(MouseStateSMC_AutoGenerated& s)
  { s.FSMError("buttonUp", s.GetState().StateName()); }

void MouseStateSMC_AutoGeneratedState::move(MouseStateSMC_AutoGenerated& s)
  { s.FSMError("move", s.GetState().StateName()); }

//----------------------------------------------
// The States and their Transitions
//----------------------------------------------

//----------------------------------------------
// MouseReady Actions and Transitions
//----------------------------------------------

// Starting State: MouseReady
// Event:          captureReleased
//
void MouseStateSMC_AutoGeneratedMouseReadyState::captureReleased( MouseStateSMC_AutoGenerated& s )
{

    s.captureReleased_();
}

// Starting State: MouseReady
// Event:          buttonDown
//
void MouseStateSMC_AutoGeneratedMouseReadyState::buttonDown( MouseStateSMC_AutoGenerated& s )
{

    // Change the state
    s.SetState(MouseStateSMC_AutoGenerated::ButtonDown);
}

// Starting State: MouseReady
// Event:          move
//
void MouseStateSMC_AutoGeneratedMouseReadyState::move( MouseStateSMC_AutoGenerated& s )
{
}

//----------------------------------------------
// ButtonDown Actions and Transitions
//----------------------------------------------

// Starting State: ButtonDown
// Event:          captureReleased
//
void MouseStateSMC_AutoGeneratedButtonDownState::captureReleased( MouseStateSMC_AutoGenerated& s )
{

    s.captureReleased_();

    // Change the state
    s.SetState(MouseStateSMC_AutoGenerated::MouseReady);
}

// Starting State: ButtonDown
// Event:          buttonUp
//
void MouseStateSMC_AutoGeneratedButtonDownState::buttonUp( MouseStateSMC_AutoGenerated& s )
{

    s.click_();
    s.buttonUp_();

    // Change the state
    s.SetState(MouseStateSMC_AutoGenerated::MouseReady);
}

// Starting State: ButtonDown
// Event:          move
//
void MouseStateSMC_AutoGeneratedButtonDownState::move( MouseStateSMC_AutoGenerated& s )
{

    s.beginDrag_();
    s.onDrag_();

    // Change the state
    s.SetState(MouseStateSMC_AutoGenerated::Drag);
}

//----------------------------------------------
// Drag Actions and Transitions
//----------------------------------------------

// Starting State: Drag
// Event:          captureReleased
//
void MouseStateSMC_AutoGeneratedDragState::captureReleased( MouseStateSMC_AutoGenerated& s )
{

    s.captureReleased_();

    // Change the state
    s.SetState(MouseStateSMC_AutoGenerated::MouseReady);
}

// Starting State: Drag
// Event:          buttonUp
//
void MouseStateSMC_AutoGeneratedDragState::buttonUp( MouseStateSMC_AutoGenerated& s )
{

    s.endDrag_();
    s.buttonUp_();

    // Change the state
    s.SetState(MouseStateSMC_AutoGenerated::MouseReady);
}

// Starting State: Drag
// Event:          move
//
void MouseStateSMC_AutoGeneratedDragState::move( MouseStateSMC_AutoGenerated& s )
{

    s.onDrag_();
}

//----------------------------------------------
// State Machine Constructor: MouseStateSMC_AutoGenerated
//  set Initial State to: MouseReady
//
//----------------------------------------------
MouseStateSMC_AutoGenerated::MouseStateSMC_AutoGenerated() : itsState(&MouseReady)
{
    // Entry functions for: MouseReady
}

//  Get version information
//
const char* MouseStateSMC_AutoGenerated::GetVersion() const
{ return _versID; }

}  // end namespace smc
