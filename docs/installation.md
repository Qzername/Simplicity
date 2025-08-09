---
sidebar_position: 2
---

# Installation

As this is still in the early stages of development, I have not published a NuGet package. I plan to do this in the future when the library is ready for it. For now, you’ll need to manually add the DLL to your project. It’s more annoying than difficult.

1. Download all three DLLs from the latest release.
2. Link Simplicity.NET.dll to your project
3. Include the other DLLs (`assimp.dll` and `Simplicity.dll`) in your project, and make sure they are set to 'Copy always' in the output directory.

Alternatively, you can place them in the same directory as your executable without adding them to your project.