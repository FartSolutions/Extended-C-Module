# Extended-Cpp-Module
A library to extend the Cpp functionalities. It is intended to provide simple use of larger systems, such as creating windows and integrating graphic APIs. It uses some open source libraries and encapsulates them in its own code.

# Libraries
|Library|Main header|Description
|-|-|-
|ecm.dll|ecm.h|Provides the basic types and functions.
|ecm.math.lib|ecm_math.hpp|Provides mathematic functions.
|ecm.algorithm.dll|ecm_algorithm.hpp|Provides some algorithms.
|ecm.window.dll|ecm_window.hpp|Provides types and functions for managing windows and their events.
|ecm.graphics.dll|ecm_graphics.hpp|Provides the basic types and functions for the graphics system.

# Dependencies
|Library|Internal dependencies|3rd party dependencies
|-|-|-
|ecm.dll|-|-
|ecm.math.dll|ecm.dll|-
|ecm.algorithm.dll|ecm.dll|-
|ecm.window.dll|ecm.dll|sdl2.dll
|ecm.opengl.dll|ecm.dll, ecm.window.dll|sdl2.dll

# Examples
## Window and graphics context
```cpp
int main()
{
  ecm::GraphicsAPI gApi{ ecm::GRAPHICSAPI_OPENGL };
  ecm::Window window = ecm::CreateWindow("Test window", { 800, 600 },
    ecm::WINDOWFLAG_RESIZABLE, ecm::WINDOWMODE_SHOWN, gApi);

  ecm::ContextBase* context = nullptr;
  if (gApi == ecm::GRAPHICSAPI_OPENGL)
    context = new ecm::gl::OpenGLContext();
  else context = new ecm::SDLRendererContext();

  context->Initialize(window);
  context->SetColor(ecm::ColorF(0x1A304Cff));
  context->SetVSyncMode(ecm::VSYNC_ENABLED);

  while (!window.IsClosed())
  {
    ecm::Event e{};
    while (ecm::PollEvent(e));

    context->ClearBuffers();
    context->SwapBuffers();
  }

  context->Shutdown();
  delete context;
  ecm::DestroyWindow(window);
}
```

&uarr; [Back to top](#top)
