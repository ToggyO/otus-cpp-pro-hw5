#include "editor.h"

Editor::Editor(const std::shared_ptr<IDocument> &model)
    : m_model{model}
{
    m_model->subscribe(shared_from_this());
}

void Editor::update() { draw(); }

void Editor::draw()
{
    auto ptr = m_model.get();
    for (auto iter = ptr->cbegin(); iter != ptr->cend(); ++iter)
    {
        iter->get()->draw();
    }
}