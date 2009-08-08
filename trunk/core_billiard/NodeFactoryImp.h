#pragma once
namespace my_render_imp {

class NodeFactoryImp : IMPLEMENTS_ NodeFactory {
public: // from NodeFactory
    virtual Node * createVisualScene( domVisual_sceneRef );
    virtual Node * find( wstring id );
    virtual void release( Node * );

public:
    NodeFactoryImp( InstanceResolver * instanceResolver );

private: // read visual_scene
    void readNode( domNodeRef node, NodeImp * parentNode );
    void readNodeTranforms( NodeImp * newNode, domNodeRef node );
    void readNodeInstanceGeometries( NodeImp * newNode, domNodeRef node );
    void readNodeInstanceControllers();
    void readNodeInstanceLights();
    void readNodeInstanceCameras();
    void readNodeChildNodes();
    void readNodeInstanceNodes();
    void readNodeInstanceGeometry();

private: // create
    NodeImp * createNode( string id, string name, string sid, NodeImp * parent );

private:
    InstanceResolver * instanceResolver_;

private:
    typedef list< NodePtr > CreatedObjects;
    CreatedObjects createdObjects_;
};

}