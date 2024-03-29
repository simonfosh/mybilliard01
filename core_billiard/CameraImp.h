#pragma once
namespace my_render_imp {


class CameraImp : public BaseImp, IMPLEMENTS_INTERFACE( Camera ) {
public: // from Camera
    virtual bool isPerspective() OVERRIDE;
    virtual bool isOrthographic() OVERRIDE;

    virtual CameraPerspective * getPerspectiveCamera() OVERRIDE;
    virtual CameraOrthographic * getOrthographicCamera() OVERRIDE;

    virtual void getProjectionMatrix44( float * returnMatrix44, bool bRightHand, bool bRowMajor ) OVERRIDE;

public:
    CameraImp();

    void setAsPerspective( bool );

private:
    bool isPerspective_;
    CameraPerspectiveImp perspectiveCamera_;
    CameraOrthographicImp orthographicCamera_;
};


}
