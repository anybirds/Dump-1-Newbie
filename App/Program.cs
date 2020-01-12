using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Engine;

namespace App
{
    class Program
    {
        static void Main(string[] args)
        {
            Window window = new Window("hello", 640, 480);
            while (!window.ShouldClose())
            {
                window.SwapBuffers();
                window.PollEvents();
            }
        }
    }
}
