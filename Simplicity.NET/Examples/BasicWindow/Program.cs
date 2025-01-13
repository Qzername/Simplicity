using Simplicity.NET;

Window window = new("Basic window");

while (!window.ShouldClose())
{
    window.FrameCalculations();
    window.Clear(new Color(50, 75, 75));

    //here goes drawing
    //for example:
    //window.Draw(Drawable)

    window.Render();
}
