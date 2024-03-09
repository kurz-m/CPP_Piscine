#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "utils.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < max_templates_; i++) {
    templates_[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource &rhs) { *this = rhs; }

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
  if (this != &rhs) {
    for (int i = 0; i < max_templates_; i++) {
      if (templates_[i] != NULL) {
        delete templates_[i];
        templates_[i] = NULL;
      }
      if (rhs.templates_[i] != NULL) {
        templates_[i] = rhs.templates_[i];
      }
    }
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < max_templates_; i++) {
    if (templates_[i] != NULL) {
      delete templates_[i];
      templates_[i] = NULL;
    }
  }
}

void MateriaSource::learn_materia(AMateria *materia) {
  for (int i = 0; i < max_templates_; i++) {
    if (templates_[i] == NULL) {
      if (dynamic_cast<Ice *>(materia) != NULL) {
        templates_[i] = new Ice(*dynamic_cast<Ice *>(materia));
      } else if (dynamic_cast<Cure *>(materia) != NULL) {
        templates_[i] = new Cure(*dynamic_cast<Cure *>(materia));
      } else {
        log_level("Unknown materia", RED, ERROR);
      }
      return;
    }
  }
  log_level("Template storage is full!", RED, ERROR);
}

AMateria *MateriaSource::create_materia(const std::string &type) {
  for (int i = 0; i < max_templates_; i++) {
    if (templates_[i] != NULL) {
      if (templates_[i]->get_type() == type) {
        return templates_[i]->clone();
      }
    }
  }
  return NULL;
}
