#pragma once
namespace my_render_imp {


class NodeFactoryImp : IMPLEMENTS_INTERFACE( NodeFactory ) {
public: // from NodeFactory
    virtual Node * createVisualScene( domVisual_sceneRef ) OVERRIDE;
    virtual Node * find( wstring id ) OVERRIDE;
    virtual bool destroyNode( Node * ) OVERRIDE;

public:
    NodeFactoryImp( InstanceResolver * instanceResolver );

private: // read visual_scene
    void readNode( NodeImp * parentNode, domNodeRef node );

    void readNodeTranforms( NodeImp * newNode, domNodeRef node );
    void readNodeInstanceGeometries( NodeImp * newNode, domNodeRef node );
    void readNodeInstanceControllers();
    void readNodeInstanceLights();
    void readNodeInstanceCameras();
    void readNodeChildNodes();
    void readNodeInstanceNodes();
    void readNodeInstanceGeometry();

private: // read transform
    NodeTransformPtr readNodeTranform( domElement * content );
    bool readNodeTransformRotate( NodeTransform * transform, domElement * content );
    bool readNodeTransformTranslate( NodeTransform * transform, domElement * content );
    bool readNodeTransformScale( NodeTransform * transform, domElement * content );
    bool readNodeTransformLookAt( NodeTransform * transform, domElement * content );
    bool readNodeTransformMatrix( NodeTransform * transform, domElement * content );

private:
    InstanceResolver * const instanceResolver_;

private: // create node
    NodeImp * createNode( wstring id, wstring name, wstring sid, NodeImp * parent );
    bool isAlreadyCreated( wstring id );
    NodeImp * findNode( wstring id );

private:
    typedef list< NodeImpPtr > Nodes;
    Nodes nodes_;
};


}