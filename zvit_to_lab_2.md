# Лабораторна робота 2  

## Звіт з лабороторної роботи №2  
За курсом "Обчислювальна геометрія та комп'юторна графіка"  
Студентки групи ПА-22-2  
Бобровицької Софії Сергіївни   
 
### 1. Постановка задачі:

![image](https://github.com/user-attachments/assets/0c86f02d-3470-4ca4-a626-1dc74075bdbf)  

![image](https://github.com/user-attachments/assets/3d0ff0fd-08de-44d5-8e9b-741248e86404)  

![image](https://github.com/user-attachments/assets/653d4704-7054-4da4-912e-8639444578fc)  

### 2. Створення унікального імені графічного рушія

Був обраний простір імен BBS як абревіатура від імені: Bobrovytska Sofiia Serhiivna.

  

![image](https://github.com/user-attachments/assets/33d90bea-fd95-4192-94a8-387751f99ff6)  

### 3. Основа коду на базі Task02Src

Було використано шаблон із Task02Src.
Код перенесено до Visual Studio 2022 з системою GLEW + GLFW. Створено власний рендерер з розширенням.


  
### 4. Діаграма UML

Було створено UML-діаграму у Mermaid-синтаксі, що ілюструє організацію просторів імен, структуру класів та спадкування:
GLRenderSystem (abstract)
GLRendererOld2_1, GLRendererPoints, GLRendererBouncingCircle
GLWindow використовує GLRenderSystem
Простір LogicCore зроблено як розширювання для логіки


```mermaid


classDiagram
    class BBS.GraphCore.GLWindow {
        - handle: GLFWwindow*
    }

    class BBS.GraphCore.GLRenderSystem {
        <<abstract>>
        + init(): void
        + render(window): void
    }

    class BBS.GraphCore.GLRendererOld2_1 {
    }

    class BBS.GraphCore.GLRendererPoints {
    }

    class BBS.GraphCore.GLRendererBouncingCircle {
    }

    BBS.GraphCore.GLRenderSystem <|-- BBS.GraphCore.GLRendererOld2_1
    BBS.GraphCore.GLRenderSystem <|-- BBS.GraphCore.GLRendererPoints
    BBS.GraphCore.GLRenderSystem <|-- BBS.GraphCore.GLRendererBouncingCircle

    BBS.GraphCore.GLWindow ..> BBS.GraphCore.GLRenderSystem : uses

    class BBS.LogicCore.OtherOperations {
        <<note>> Look in Pattern
    }

    BBS.GraphCore.GLRenderSystem .. BBS.LogicCore.OtherOperations
```

### 5. Вивід до консолі

До main() додано основний вивід:

![image](https://github.com/user-attachments/assets/bfb3ef7e-ae44-4b36-a315-8cf852e4caa2)  

### 6. Створено 3 вікна

За допомогою GLWindow створено 3 незалежні вікна. Кожне отримує власний OpenGL-контекст.

### 7. Об'єкт VBO (GLRendererPoints)

Створено VAO/VBO, передані 3 точки, які відображаються через glDrawArrays(GL_POINTS)  

### 8. glDrawArrays()


![image](https://github.com/user-attachments/assets/2e89848b-140e-419c-b143-290c9f37e2cf)



### 9. Дві рендерні машини

У вікні 1: GLRendererPoints малює точки

У вікні 2: GLRendererOld2_1 малює обертовий трикутник (glBegin, glEnd)

У вікні 3: GLRendererBouncingCircle — реалізація кола, що рухається та відбивається

Усі 3 рендерери реалізують інтерфейс GLRenderSystem і викликаються через спільний API.  



### 10. Результат:

![image](https://github.com/user-attachments/assets/fab76689-3519-4ea0-aafd-a78813883aad)  

![image](https://github.com/user-attachments/assets/706d97b6-375c-4fa9-88da-a05346137df9)  

![image](https://github.com/user-attachments/assets/7c878a73-0431-481f-9dfb-250123721c1a)  

![image](https://github.com/user-attachments/assets/5eefb50c-a30a-4486-b3aa-e54325b79a83)  






