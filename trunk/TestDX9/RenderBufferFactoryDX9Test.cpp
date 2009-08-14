#include "stdafx.h"
#include "RenderBufferFactoryDX9Test_Backdoor.hpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace TestDX9
{
	[TestClass]
	public ref class RenderBufferFactoryDX9Test
	{
    private:
        RenderWin32DX9 * dx9;
        RenderWin32DX9Imp * dx9Imp;
        RenderBufferFactory * factory;

    public: 
        [TestInitialize()]
        void MyTestInitialize() {
            dx9 = (dx9Imp) = new RenderWin32DX9Imp();
            dx9->setBackbufferLockable( true );
            Assert::IsTrue( dx9->createDevice( true, 30, 30 ) );
            factory = PRIVATE_METHOD( RenderWin32DX9Imp, getBufferFactory )( dx9Imp );
        };

        [TestCleanup()]
        void MyTestCleanup() {
            dx9->destroyDevice();
            delete dx9;
        };

    public:
		[TestMethod]
		void FixtureTesting()
		{
		};

        [TestMethod]
        void CreateVertexBuffer_static()
        {
        };
    };
}