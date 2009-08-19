#pragma once
namespace my_render_win32_dx9_imp {


class RenderStateDX9Imp : IMPLEMENTS_INTERFACE( RenderStateDX9 ) {
public: // from RenderState
    virtual const RenderState_Wireframe * getWireframe() const OVERRIDE;
    virtual RenderState_Wireframe * setWireframe() OVERRIDE;

    virtual const RenderState_Cull * getCull() const OVERRIDE;
    virtual RenderState_Cull * setCull() OVERRIDE;

public:
    RenderStateDX9Imp( LPDIRECT3DDEVICE9 d3d9Device );

private:
    LPDIRECT3DDEVICE9 d3d9Device_;

private:
    RenderState_WireframeDX9Ptr wireframe_;
    RenderState_CullDX9Ptr cull_;
};


}