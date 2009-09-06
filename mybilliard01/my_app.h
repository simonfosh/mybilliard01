#pragma once
#include "DXUT.h"
#include "SDKmisc.h"
#include "SDKmesh.h"
#include "resource.h"

#include "../core_billiard/my_phys.h"
#include "../core_billiard/my_open_al_imp.h"
#include "../render_win32/my_render_win32_dx9_imp.h"

#pragma warning( disable: 4201 )
#include "tinyxml.h"

#include "targetver.h"


using namespace std;
using namespace my_render;
using namespace my_render_win32;
using namespace my_render_win32_dx9;

using namespace my_render_imp;
using namespace my_render_win32_imp;
using namespace my_render_win32_dx9_imp;

using namespace my_phys;
using namespace my_open_al;
using namespace my_open_al_imp;


class MyRenderEventListenerImp;
class MyInputListenerImp;
class MyCamera;
class MyEffectShaderFeeder;
class NodeDisplayer;
class RenderableCamera;


MY_SMART_PTR( MyRenderEventListenerImp );
MY_SMART_PTR( MyInputListenerImp );
MY_SMART_PTR( MyCamera );
MY_SMART_PTR( MyEffectShaderFeeder );
MY_SMART_PTR( NodeDisplayer );
MY_SMART_PTR( RenderableCamera );


#include "BilliardControl.h"

#include "MyCameraModeSMC.h"
#include "MyCameraTopViewSMC.h"
#include "MyCameraAimViewSMC.h"
#include "MyCameraMoveViewMoveSMC.h"
#include "MyCameraMoveViewRotateSMC.h"

#include "MyCameraModeSMC_AutoGenerated.h"
#include "MyCameraTopViewSMC_AutoGenerated.h"
#include "MyCameraAimViewSMC_AutoGenerated.h"
#include "MyCameraMoveViewMoveSMC_AutoGenerated.h"
#include "MyCameraMoveViewRotateSMC_AutoGenerated.h"
using namespace smc;

#include "MyCameraState.h"
#include "MouseStateSMC.h"
#include "MouseStateSMC_AutoGenerated.h"

#include "SoundRetriever.h"
#include "ActorRecognizer.h"
#include "MyControllerHitReport.hpp"
#include "RenderableCamera.h"
#include "MyCamera.h"

#include "BallContactReport.h"
#include "MyInputListenerImp.h"

#include "RenderMonkeySemantics.hpp"
#include "RenderMonkeySemanticFeeder.h"
#include "MyEffectShaderFeeder.h"
#include "MyEffectShaderFeederImp.h"
#include "NodeDisplayer.h"

#include "MyRenderEventListenerImp.h"
#include "ConstString.h"

