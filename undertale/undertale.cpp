// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "undertale.h"

#include <iostream>
#include <fstream>

undertale_t::undertale_t(kaitai::kstream *p_io, kaitai::kstruct *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = this;
    m_form = new form_t(m__io, this, m__root);
}

undertale_t::~undertale_t() {
    delete m_form;
}

undertale_t::tmln_t::tmln_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x54\x4D\x4C\x4E", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::tmln_t::~tmln_t() {
}

undertale_t::dafl_t::dafl_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x44\x41\x46\x4C", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::dafl_t::~dafl_t() {
}

undertale_t::path_t::path_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x50\x41\x54\x48", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::path_t::~path_t() {
}

undertale_t::gen8_t::gen8_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x47\x45\x4E\x38", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::gen8_t::~gen8_t() {
}

undertale_t::optn_t::optn_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x4F\x50\x54\x4E", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::optn_t::~optn_t() {
}

undertale_t::agrp_t::agrp_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x41\x47\x52\x50", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::agrp_t::~agrp_t() {
}

undertale_t::bgnd_t::bgnd_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x42\x47\x4E\x44", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::bgnd_t::~bgnd_t() {
}

undertale_t::txtr_t::txtr_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x54\x58\x54\x52", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::txtr_t::~txtr_t() {
}

undertale_t::tpag_t::tpag_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x54\x50\x41\x47", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::tpag_t::~tpag_t() {
}

undertale_t::string_t::string_t(kaitai::kstream *p_io, undertale_t::strg_data_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_size = m__io->read_u4le();
    m_string = m__io->read_str_byte_limit((size() + 1), "ascii");
}

undertale_t::string_t::~string_t() {
}

undertale_t::code_t::code_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x43\x4F\x44\x45", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::code_t::~code_t() {
}

undertale_t::strg_data_t::strg_data_t(kaitai::kstream *p_io, undertale_t::strg_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_count = m__io->read_u4le();
    int l_offsets = count();
    m_offsets = new std::vector<uint32_t>();
    m_offsets->reserve(l_offsets);
    for (int i = 0; i < l_offsets; i++) {
        m_offsets->push_back(m__io->read_u4le());
    }
    int l_strings = count();
    m_strings = new std::vector<string_t*>();
    m_strings->reserve(l_strings);
    for (int i = 0; i < l_strings; i++) {
        m_strings->push_back(new string_t(m__io, this, m__root));
    }
}

undertale_t::strg_data_t::~strg_data_t() {
    delete m_offsets;
    for (std::vector<string_t*>::iterator it = m_strings->begin(); it != m_strings->end(); ++it) {
        delete *it;
    }
    delete m_strings;
}

undertale_t::scpt_t::scpt_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x53\x43\x50\x54", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::scpt_t::~scpt_t() {
}

undertale_t::font_t::font_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x46\x4F\x4E\x54", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::font_t::~font_t() {
}

undertale_t::sprt_t::sprt_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x53\x50\x52\x54", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::sprt_t::~sprt_t() {
}

undertale_t::audo_t::audo_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x41\x55\x44\x4F", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::audo_t::~audo_t() {
}

undertale_t::vari_t::vari_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x56\x41\x52\x49", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::vari_t::~vari_t() {
}

undertale_t::extn_t::extn_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x45\x58\x54\x4E", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::extn_t::~extn_t() {
}

undertale_t::strg_t::strg_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x53\x54\x52\x47", 4));
    m_size = m__io->read_u4le();
    m__raw_data = m__io->read_bytes(size());
    m__io__raw_data = new kaitai::kstream(m__raw_data);
    m_data = new strg_data_t(m__io__raw_data, this, m__root);
}

undertale_t::strg_t::~strg_t() {
    delete m__io__raw_data;
    delete m_data;
}

undertale_t::func_t::func_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x46\x55\x4E\x43", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::func_t::~func_t() {
}

undertale_t::room_t::room_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x52\x4F\x4F\x4D", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::room_t::~room_t() {
}

undertale_t::form_t::form_t(kaitai::kstream *p_io, undertale_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x46\x4F\x52\x4D", 4));
    m_size = m__io->read_u4le();
    m_gen8 = new gen8_t(m__io, this, m__root);
    m_optn = new optn_t(m__io, this, m__root);
    m_extn = new extn_t(m__io, this, m__root);
    m_sond = new sond_t(m__io, this, m__root);
    m_agrp = new agrp_t(m__io, this, m__root);
    m_sprt = new sprt_t(m__io, this, m__root);
    m_bgnd = new bgnd_t(m__io, this, m__root);
    m_path = new path_t(m__io, this, m__root);
    m_scpt = new scpt_t(m__io, this, m__root);
    m_shdr = new shdr_t(m__io, this, m__root);
    m_font = new font_t(m__io, this, m__root);
    m_tmln = new tmln_t(m__io, this, m__root);
    m_objt = new objt_t(m__io, this, m__root);
    m_room = new room_t(m__io, this, m__root);
    m_dafl = new dafl_t(m__io, this, m__root);
    m_tpag = new tpag_t(m__io, this, m__root);
    m_code = new code_t(m__io, this, m__root);
    m_vari = new vari_t(m__io, this, m__root);
    m_func = new func_t(m__io, this, m__root);
    m_strg = new strg_t(m__io, this, m__root);
    m_txtr = new txtr_t(m__io, this, m__root);
    m_audo = new audo_t(m__io, this, m__root);
    n_l18n = true;
    if (size() > _io()->pos()) {
        n_l18n = false;
        m_l18n = new strg_t(m__io, this, m__root);
    }
}

undertale_t::form_t::~form_t() {
    delete m_gen8;
    delete m_optn;
    delete m_extn;
    delete m_sond;
    delete m_agrp;
    delete m_sprt;
    delete m_bgnd;
    delete m_path;
    delete m_scpt;
    delete m_shdr;
    delete m_font;
    delete m_tmln;
    delete m_objt;
    delete m_room;
    delete m_dafl;
    delete m_tpag;
    delete m_code;
    delete m_vari;
    delete m_func;
    delete m_strg;
    delete m_txtr;
    delete m_audo;
    if (!n_l18n) {
        delete m_l18n;
    }
}

undertale_t::objt_t::objt_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x4F\x42\x4A\x54", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::objt_t::~objt_t() {
}

undertale_t::sond_t::sond_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x53\x4F\x4E\x44", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::sond_t::~sond_t() {
}

undertale_t::shdr_t::shdr_t(kaitai::kstream *p_io, undertale_t::form_t *p_parent, undertale_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_magic = m__io->ensure_fixed_contents(std::string("\x53\x48\x44\x52", 4));
    m_size = m__io->read_u4le();
    m_data = m__io->read_bytes(size());
}

undertale_t::shdr_t::~shdr_t() {
}
