#include "raylib.h"
     
int main(void)
{
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "example - sprite button");

    InitAudioDevice();      

    Sound fxButton = LoadSound("resources/buttonfx.wav");   
    Image button_image = LoadImage("resources/buttons.png"); 

    Texture2D button_red = LoadTextureFromImage(button_image);
    Texture2D button_green = LoadTextureFromImage(button_image);
    Texture2D button_yellow = LoadTextureFromImage(button_image);

    //red button
    Rectangle button_red_up = {256,0,128,56}; //расположение button_red_up на атласе и её размер
    Rectangle button_red_down = {128,0,128,56}; //расположение button_red_down на атласе и её размер
    Rectangle button_red_source; //принимает состояние кнопки для отрисовки
    Rectangle button_red_bounds = {256,176,128,56}; //позиция на экране и размер прямоугольника
    Rectangle button_red_state; //состояние кнопки             
    bool button_red_action = false; //нажата ли кнопка ?

    //green button
    Rectangle button_green_up = {0,56,128,56}; //расположение button_green_up на атласе и её размер
    Rectangle button_green_down = {0,0,128,56}; //расположение button_green_down на атласе и её размер
    Rectangle button_green_source; //принимает состояние кнопки для отрисовки
    Rectangle button_green_bounds = {256,240,128,56}; //позиция на экране и размер прямоугольника
    Rectangle button_green_state; //состояние кнопки            
    bool button_green_action = false; //нажата ли кнопка ?

    //yellow button
    Rectangle button_yellow_up = {256,56,128,56}; //расположение button_yellow_up на атласе и её размер
    Rectangle button_yellow_down = {128,56,128,56}; //расположение button_yellow_down на атласе и её размер
    Rectangle button_yellow_source; //принимает состояние кнопки для отрисовки
    Rectangle button_yellow_bounds = {256,304,128,56}; //позиция на экране и размер прямоугольника
    Rectangle button_yellow_state; //состояние кнопки          
    bool button_yellow_action = false; //нажата ли кнопка ?
    
    
    Vector2 mousePoint = { 0.0f, 0.0f };

    UnloadImage(button_image);

    SetTargetFPS(60);
    
    while (!WindowShouldClose())    
    {
        mousePoint = GetMousePosition();

        //button red
        button_red_action = false;

        if (CheckCollisionPointRec(mousePoint, button_red_bounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) button_red_state = button_red_down; //если левая кнопка мыши нажата 
            else button_red_state = button_red_up; //если не нажата

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) button_red_action = true;
        }
        else button_red_state = button_red_up;

        if (button_red_action)
        {
            PlaySound(fxButton);
        }

          button_red_source = button_red_state; //определение кадра для отрисовки

        //button green
        button_green_action = false;

        if (CheckCollisionPointRec(mousePoint, button_green_bounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) button_green_state = button_green_down; //если левая кнопка мыши нажата
            else button_green_state = button_green_up; //если не нажата

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) button_green_action = true;
        }
        else button_green_state = button_green_up;

        if (button_green_action)
        {
            PlaySound(fxButton);
        }

          button_green_source = button_green_state; //определение кадра для отрисовки

        //button yellow
        button_yellow_action = false;

        if (CheckCollisionPointRec(mousePoint, button_yellow_bounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) button_yellow_state = button_yellow_down; //если левая кнопка мыши нажата
            else button_yellow_state = button_yellow_up; //если не нажата

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) button_yellow_action = true;
        }
        else button_yellow_state = button_yellow_up;

        if (button_yellow_action)
        {
            OpenURL("https://www.raylib.com/");
        }

          button_yellow_source = button_yellow_state; //определение кадра для отрисовки

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextureRec(button_red, button_red_source, (Vector2){ button_red_bounds.x, button_red_bounds.y }, WHITE); 
        DrawTextureRec(button_green, button_green_source, (Vector2){ button_green_bounds.x, button_green_bounds.y }, WHITE); 
        DrawTextureRec(button_yellow, button_yellow_source, (Vector2){ button_yellow_bounds.x, button_yellow_bounds.y }, WHITE); 
        EndDrawing();
    }

    UnloadTexture(button_red);  
    UnloadTexture(button_green);
    UnloadTexture(button_yellow);

    UnloadSound(fxButton); 

    CloseAudioDevice();     

    CloseWindow();         

    return 0;
}
