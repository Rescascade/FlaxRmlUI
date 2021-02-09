using System;
using System.Collections.Generic;
using FlaxEngine;
using FlaxEngine.GUI;
using FlaxEditor;

namespace Game
{
    public class RmlManagedActor : Control
    {

        RmlSceneActor rmlSceneActor;
        bool IsInitialized = false;

        public override void Draw()
        {
            base.Draw();
            if (Editor.IsPlayMode)
            {
                if (!IsInitialized)
                {
                    /*  rmlSceneActor = Control.GetScript<RmlSceneActor>();*/

                    rmlSceneActor = new RmlSceneActor();

                    rmlSceneActor.InitializeRML();

                    IsInitialized = true;
                }

                if (IsInitialized)
                {
                    rmlSceneActor.OnDrawRML();
                }
            }

            
            

        }


        public override void OnDestroy()
        {
           

            if (Editor.IsPlayMode)
            {
                if (IsInitialized)
                {
                    
                    rmlSceneActor.DestroyRML();
                }
            }

            base.OnDestroy();  
        }
    }
}
