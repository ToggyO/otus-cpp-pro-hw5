#include "circle.h"
#include "controller.h"
#include "document.h"
#include "editor.h"
#include "point.h"

int main()
{
    const auto document_ptr = std::make_shared<Document>();
    Controller controller(document_ptr);
    Editor view(document_ptr);

    controller.add_point(5, 10);

    Point point(4, 5);
    controller.add_circle(point, 5);
}
