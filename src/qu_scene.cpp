// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "../include/qu_scene.h"
qu_show_t::qu_show_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, qu_show_t* p__root) : kaitai::kstruct(p__io){
    m__parent = p__parent;
    m__root = this;
    _read();
}
void qu_show_t::_read(){
    name = m__io->read_bytes(4*9);
}

kaitai::kstream* qu_show_t::Write(std::string filepath){
    kaitai::kstream* p_io = m__io;
    p_io->begin_write(filepath + "/SHOW.DAT");
    std::cout << name << std::endl;
    p_io->write_bytes(name,name.length());
    p_io->getFStream()->close();
    return p_io;
}

qu_scene_t::qu_scene_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    _read();
}

void qu_scene_t::_read() {
    m_header = new header_t(m__io, this, m__root);
    m_header_end = new section_end_t(m__io, this, m__root);
    int l_inputs = 32;
    m_inputs = new std::vector<channel_entry_t*>();
    m_inputs->reserve(l_inputs);
    for (int i = 0; i < l_inputs; i++) {
        m_inputs->push_back(new channel_entry_t(m__io, this, m__root));
    }
    int l_stereo_inputs = 3;
    m_stereo_inputs = new std::vector<channel_entry_t*>();
    m_stereo_inputs->reserve(l_stereo_inputs);
    for (int i = 0; i < l_stereo_inputs; i++) {
        m_stereo_inputs->push_back(new channel_entry_t(m__io, this, m__root));
    }
    int l_fx_returns = 4;
    m_fx_returns = new std::vector<channel_entry_t*>();
    m_fx_returns->reserve(l_fx_returns);
    for (int i = 0; i < l_fx_returns; i++) {
        m_fx_returns->push_back(new channel_entry_t(m__io, this, m__root));
    }
    int l_mixes = 7;
    m_mixes = new std::vector<channel_entry_t*>();
    m_mixes->reserve(l_mixes);
    for (int i = 0; i < l_mixes; i++) {
        m_mixes->push_back(new channel_entry_t(m__io, this, m__root));
    }
    m_lr = new channel_entry_t(m__io, this, m__root);
    int l_groups = 4;
    m_groups = new std::vector<channel_entry_t*>();
    m_groups->reserve(l_groups);
    for (int i = 0; i < l_groups; i++) {
        m_groups->push_back(new channel_entry_t(m__io, this, m__root));
    }
    int l_matrices = 2;
    m_matrices = new std::vector<channel_entry_t*>();
    m_matrices->reserve(l_matrices);
    for (int i = 0; i < l_matrices; i++) {
        m_matrices->push_back(new channel_entry_t(m__io, this, m__root));
    }
    int l_chan12 = 2;
    m_chan12 = new std::vector<channel_entry_t*>();
    m_chan12->reserve(l_chan12);
    for (int i = 0; i < l_chan12; i++) {
        m_chan12->push_back(new channel_entry_t(m__io, this, m__root));
    }
    int l_fx_sends = 4;
    m_fx_sends = new std::vector<channel_entry_t*>();
    m_fx_sends->reserve(l_fx_sends);
    for (int i = 0; i < l_fx_sends; i++) {
        m_fx_sends->push_back(new channel_entry_t(m__io, this, m__root));
    }
    m_chan3 = new channel_entry_t(m__io, this, m__root);
    m_channel_end = new section_end_t(m__io, this, m__root);
    int l_fx_rack = 4;
    m_fx_rack = new std::vector<fx_rack_entry_t*>();
    m_fx_rack->reserve(l_fx_rack);
    for (int i = 0; i < l_fx_rack; i++) {
        m_fx_rack->push_back(new fx_rack_entry_t(m__io, this, m__root));
    }
    m_fx_rack_end = new section_end_t(m__io, this, m__root);
    int l_routing = 60;
    m_routing = new std::vector<routing_entry_t*>();
    m_routing->reserve(l_routing);
    for (int i = 0; i < l_routing; i++) {
        m_routing->push_back(new routing_entry_t(m__io, this, m__root));
    }
    m_routing_end = new section_end_t(m__io, this, m__root);
    m_sect5 = m__io->read_bytes(0);
    m_sect5_end = new section_end_t(m__io, this, m__root);
    m_sect6 = m__io->read_bytes(4);
    m_sect6_end = new section_end_t(m__io, this, m__root);
    m_additive_pafl = m__io->read_u1();
    m_sect7 = m__io->read_bytes(11);
    m_sect7_end = new section_end_t(m__io, this, m__root);
    m_sect8 = m__io->read_bytes(24);
    m_sect8_end = new section_end_t(m__io, this, m__root);
    m_siggen_type = m__io->read_u1();
    m_sect9 = m__io->read_bytes(23);
    m_sect9_end = new section_end_t(m__io, this, m__root);
    int l_softkeys = 16;
    m_softkeys = new std::vector<softkey_t*>();
    m_softkeys->reserve(l_softkeys);
    for (int i = 0; i < l_softkeys; i++) {
        m_softkeys->push_back(new softkey_t(m__io, this, m__root));
    }
    m_softkeys_end = new section_end_t(m__io, this, m__root);
    m_unk1 = m__io->read_bytes(45);
    int l_usb_patch = 32;
    m_usb_patch = new std::vector<uint8_t>();
    m_usb_patch->reserve(l_usb_patch);
    for (int i = 0; i < l_usb_patch; i++) {
        m_usb_patch->push_back(m__io->read_u1());
    }
    int l_unk2 = 32;
    m_unk2 = new std::vector<std::string>();
    m_unk2->reserve(l_unk2);
    for (int i = 0; i < l_unk2; i++) {
        m_unk2->push_back(m__io->ensure_fixed_contents(std::string("\x00", 1)));
    }
    m_usb_insert_do = m__io->read_bytes(1);
    int l_unk3 = 18;
    m_unk3 = new std::vector<std::string>();
    m_unk3->reserve(l_unk3);
    for (int i = 0; i < l_unk3; i++) {
        m_unk3->push_back(m__io->ensure_fixed_contents(std::string("\xFF", 1)));
    }
    int l_surface_patch = 32;
    m_surface_patch = new std::vector<uint8_t>();
    m_surface_patch->reserve(l_surface_patch);
    for (int i = 0; i < l_surface_patch; i++) {
        m_surface_patch->push_back(m__io->read_u1());
    }
    int l_unk4 = 8;
    m_unk4 = new std::vector<std::string>();
    m_unk4->reserve(l_unk4);
    for (int i = 0; i < l_unk4; i++) {
        m_unk4->push_back(m__io->ensure_fixed_contents(std::string("\xFF", 1)));
    }
    m_patching_end = new section_end_t(m__io, this, m__root);
    m_sect12unk1 = m__io->read_bytes(2461);
    m_midi_daw_channel = m__io->read_u1();
    m_sect12unk2 = m__io->ensure_fixed_contents(std::string("\x01\x00", 2));
    int l_dsnake_out_patching = 12;
    m_dsnake_out_patching = new std::vector<uint8_t>();
    m_dsnake_out_patching->reserve(l_dsnake_out_patching);
    for (int i = 0; i < l_dsnake_out_patching; i++) {
        m_dsnake_out_patching->push_back(m__io->read_u1());
    }
    int l_dsnake_out_expander_patching = 8;
    m_dsnake_out_expander_patching = new std::vector<uint8_t>();
    m_dsnake_out_expander_patching->reserve(l_dsnake_out_expander_patching);
    for (int i = 0; i < l_dsnake_out_expander_patching; i++) {
        m_dsnake_out_expander_patching->push_back(m__io->read_u1());
    }
    int l_monitor_patching = 40;
    m_monitor_patching = new std::vector<uint8_t>();
    m_monitor_patching->reserve(l_monitor_patching);
    for (int i = 0; i < l_monitor_patching; i++) {
        m_monitor_patching->push_back(m__io->read_u1());
    }
    m_unk5 = m__io->ensure_fixed_contents(std::string("\x00\x00\x00\x00", 4));
    int l_dcas = 4;
    m_dcas = new std::vector<dca_t*>();
    m_dcas->reserve(l_dcas);
    for (int i = 0; i < l_dcas; i++) {
        m_dcas->push_back(new dca_t(m__io, this, m__root));
    }
    int l_unused_dca = 12;
    m_unused_dca = new std::vector<dca_t*>();
    m_unused_dca->reserve(l_unused_dca);
    for (int i = 0; i < l_unused_dca; i++) {
        m_unused_dca->push_back(new dca_t(m__io, this, m__root));
    }
    int l_mutegroups = 4;
    m_mutegroups = new std::vector<mutegroup_t*>();
    m_mutegroups->reserve(l_mutegroups);
    for (int i = 0; i < l_mutegroups; i++) {
        m_mutegroups->push_back(new mutegroup_t(m__io, this, m__root));
    }
    m_sect12unk3 = m__io->read_bytes(37);
    int l_qucontroltabs = 5;
    m_qucontroltabs = new std::vector<qu_control_tab_t*>();
    m_qucontroltabs->reserve(l_qucontroltabs);
    for (int i = 0; i < l_qucontroltabs; i++) {
        m_qucontroltabs->push_back(new qu_control_tab_t(m__io, this, m__root));
    }
    m_sect12unk4 = m__io->read_bytes(18);
    m_amm = new amm_t(m__io, this, m__root);
    m_sect12unk5 = m__io->ensure_fixed_contents(std::string("\x00\x00", 2));
    int l_footswitches = 4;
    m_footswitches = new std::vector<uint16_t>();
    m_footswitches->reserve(l_footswitches);
    for (int i = 0; i < l_footswitches; i++) {
        m_footswitches->push_back(m__io->read_u2le());
    }
    int l_sect12unk6 = 805;
    m_sect12unk6 = new std::vector<std::string>();
    m_sect12unk6->reserve(l_sect12unk6);
    for (int i = 0; i < l_sect12unk6; i++) {
        m_sect12unk6->push_back(m__io->ensure_fixed_contents(std::string("\x00", 1)));
    }
    m_sect12unk7 = m__io->read_bytes(1);
    m_sect12_end = new section_end_t(m__io, this, m__root);
    m_crc = m__io->read_u4le();
    if(m_crc != makeCrc(m__io,true)){
        throw std::runtime_error("WARNING CRC of input file is incorrect");
    }
}

kaitai::kstream* qu_scene_t::Write(std::string filename) {
    kaitai::kstream* p_io = m__io;
    p_io->begin_write(filename);
    m_header->Write(p_io);
    m_header_end->Write(p_io);
    int l_inputs = 32;
    for (int i = 0; i < l_inputs; i++) {
        (*m_inputs)[i]->Write(p_io);
    }
    int l_stereo_inputs = 3;
    for (int i = 0; i < l_stereo_inputs; i++) {
        (*m_stereo_inputs)[i]->Write(p_io);
    }
    int l_fx_returns = 4;
    for (int i = 0; i < l_fx_returns; i++) {
        (*m_fx_returns)[i]->Write(p_io);
    }
    int l_mixes = 7;
    for (int i = 0; i < l_mixes; i++) {
        (*m_mixes)[i]->Write(p_io);
    }
    m_lr->Write(p_io);
    int l_groups = 4;
    for (int i = 0; i < l_groups; i++) {
        (*m_groups)[i]->Write(p_io);
    }
    int l_matrices = 2;
    for (int i = 0; i < l_matrices; i++) {
        (*m_matrices)[i]->Write(p_io);
    }
    int l_chan12 = 2;
    for (int i = 0; i < l_chan12; i++) {
        (*m_chan12)[i]->Write(p_io);
    }
    int l_fx_sends = 4;
    for (int i = 0; i < l_fx_sends; i++) {
        (*m_fx_sends)[i]->Write(p_io);
    }
    m_chan3->Write(p_io);
    m_channel_end->Write(p_io);
    int l_fx_rack = 4;
    for (int i = 0; i < l_fx_rack; i++) {
        (*m_fx_rack)[i]->Write(p_io);
    }
    m_fx_rack_end->Write(p_io);
    int l_routing = 60;
    for (int i = 0; i < l_routing; i++) {
        (*m_routing)[i]->Write(p_io);
    }
    m_routing_end->Write(p_io);
    p_io->write_bytes(m_sect5,0);
    m_sect5_end->Write(p_io);
    p_io->write_bytes(m_sect6,4);
    m_sect6_end->Write(p_io);
    p_io->write_u1(m_additive_pafl);
    p_io->write_bytes(m_sect7,11);
    m_sect7_end->Write(p_io);
    p_io->write_bytes(m_sect8,24);
    m_sect8_end->Write(p_io);
    p_io->write_u1(m_siggen_type);
    p_io->write_bytes(m_sect9,23);
    m_sect9_end->Write(p_io);
    int l_softkeys = 16;
    for (int i = 0; i < l_softkeys; i++) {
        (*m_softkeys)[i]->Write(p_io);
    }
    m_softkeys_end->Write(p_io);
    p_io->write_bytes(m_unk1,45);
    int l_usb_patch = 32;
    for (int i = 0; i < l_usb_patch; i++) {
        p_io->write_u1((*m_usb_patch)[i]);
    }
    int l_unk2 = 32;
    for (int i = 0; i < l_unk2; i++) {
        p_io->write_bytes((*m_unk2)[i],1);// MAYBE SHOULD FORCE "\x00"???
    }
    p_io->write_bytes(m_usb_insert_do,1);
    int l_unk3 = 18;
    for (int i = 0; i < l_unk3; i++) {
        p_io->write_bytes((*m_unk3)[i],1);// MAYBE SHOULD FORCE "\xFF"???
    }
    int l_surface_patch = 32;
    for (int i = 0; i < l_surface_patch; i++) {
        p_io->write_u1((*m_surface_patch)[i]);
    }
    int l_unk4 = 8;
    for (int i = 0; i < l_unk4; i++) {
        p_io->write_bytes((*m_unk4)[i],1);// MAYBE SHOULD FORCE "\xFF"???
    }
    m_patching_end->Write(p_io);
    p_io->write_bytes(m_sect12unk1,2461);
    p_io->write_u1(m_midi_daw_channel);
    p_io->write_bytes(m_sect12unk2,2); // MAYBE SHOULD FORCE "\x01\x00"???
    int l_dsnake_out_patching = 12;
    for (int i = 0; i < l_dsnake_out_patching; i++) {
        p_io->write_u1((*m_dsnake_out_patching)[i]);
    }
    int l_dsnake_out_expander_patching = 8;
    for (int i = 0; i < l_dsnake_out_expander_patching; i++) {
        p_io->write_u1((*m_dsnake_out_expander_patching)[i]);
    }
    int l_monitor_patching = 40;
    for (int i = 0; i < l_monitor_patching; i++) {
        p_io->write_u1((*m_monitor_patching)[i]);
    }
    p_io->write_bytes(m_unk5,4); // MAYBE SHOULD FORCE "\x00\x00\x00\x00"???
    int l_dcas = 4;
    for (int i = 0; i < l_dcas; i++) {
        (*m_dcas)[i]->Write(p_io);
    }
    int l_unused_dca = 12;
    for (int i = 0; i < l_unused_dca; i++) {
        (*m_unused_dca)[i]->Write(p_io);
    }
    int l_mutegroups = 4;
    for (int i = 0; i < l_mutegroups; i++) {
        (*m_mutegroups)[i]->Write(p_io);
    }
    p_io->write_bytes(m_sect12unk3,37);
    int l_qucontroltabs = 5;
    for (int i = 0; i < l_qucontroltabs; i++) {
        (*m_qucontroltabs)[i]->Write(p_io);
    }
    p_io->write_bytes(m_sect12unk4,18);
    m_amm->Write(p_io);
    p_io->write_bytes(m_sect12unk5,2); // MAYBE SHOULD FORCE "\x00\x00"???
    int l_footswitches = 4;
    for (int i = 0; i < l_footswitches; i++) {
        p_io->write_u2le((*m_footswitches)[i]);
    }
    int l_sect12unk6 = 805;
    for (int i = 0; i < l_sect12unk6; i++) {
        p_io->write_bytes((*m_sect12unk6)[i],1);// MAYBE SHOULD FORCE "\x00"???
    }
    p_io->write_bytes(m_sect12unk7,1);
    m_sect12_end->Write(p_io);
    p_io->write_u4le(makeCrc(p_io,false));
    p_io->getFStream()->close();
    return p_io;
}

qu_scene_t::~qu_scene_t() {
    delete m_header;
    delete m_header_end;
    for (std::vector<channel_entry_t*>::iterator it = m_inputs->begin(); it != m_inputs->end(); ++it) {
        delete *it;
    }
    delete m_inputs;
    for (std::vector<channel_entry_t*>::iterator it = m_stereo_inputs->begin(); it != m_stereo_inputs->end(); ++it) {
        delete *it;
    }
    delete m_stereo_inputs;
    for (std::vector<channel_entry_t*>::iterator it = m_fx_returns->begin(); it != m_fx_returns->end(); ++it) {
        delete *it;
    }
    delete m_fx_returns;
    for (std::vector<channel_entry_t*>::iterator it = m_mixes->begin(); it != m_mixes->end(); ++it) {
        delete *it;
    }
    delete m_mixes;
    delete m_lr;
    for (std::vector<channel_entry_t*>::iterator it = m_groups->begin(); it != m_groups->end(); ++it) {
        delete *it;
    }
    delete m_groups;
    for (std::vector<channel_entry_t*>::iterator it = m_matrices->begin(); it != m_matrices->end(); ++it) {
        delete *it;
    }
    delete m_matrices;
    for (std::vector<channel_entry_t*>::iterator it = m_chan12->begin(); it != m_chan12->end(); ++it) {
        delete *it;
    }
    delete m_chan12;
    for (std::vector<channel_entry_t*>::iterator it = m_fx_sends->begin(); it != m_fx_sends->end(); ++it) {
        delete *it;
    }
    delete m_fx_sends;
    delete m_chan3;
    delete m_channel_end;
    for (std::vector<fx_rack_entry_t*>::iterator it = m_fx_rack->begin(); it != m_fx_rack->end(); ++it) {
        delete *it;
    }
    delete m_fx_rack;
    delete m_fx_rack_end;
    for (std::vector<routing_entry_t*>::iterator it = m_routing->begin(); it != m_routing->end(); ++it) {
        delete *it;
    }
    delete m_routing;
    delete m_routing_end;
    delete m_sect5_end;
    delete m_sect6_end;
    delete m_sect7_end;
    delete m_sect8_end;
    delete m_sect9_end;
    for (std::vector<softkey_t*>::iterator it = m_softkeys->begin(); it != m_softkeys->end(); ++it) {
        delete *it;
    }
    delete m_softkeys;
    delete m_softkeys_end;
    delete m_usb_patch;
    delete m_unk2;
    delete m_unk3;
    delete m_surface_patch;
    delete m_unk4;
    delete m_patching_end;
    delete m_dsnake_out_patching;
    delete m_dsnake_out_expander_patching;
    delete m_monitor_patching;
    for (std::vector<dca_t*>::iterator it = m_dcas->begin(); it != m_dcas->end(); ++it) {
        delete *it;
    }
    delete m_dcas;
    for (std::vector<dca_t*>::iterator it = m_unused_dca->begin(); it != m_unused_dca->end(); ++it) {
        delete *it;
    }
    delete m_unused_dca;
    for (std::vector<mutegroup_t*>::iterator it = m_mutegroups->begin(); it != m_mutegroups->end(); ++it) {
        delete *it;
    }
    delete m_mutegroups;
    for (std::vector<qu_control_tab_t*>::iterator it = m_qucontroltabs->begin(); it != m_qucontroltabs->end(); ++it) {
        delete *it;
    }
    delete m_qucontroltabs;
    delete m_amm;
    delete m_footswitches;
    delete m_sect12unk6;
    delete m_sect12_end;
}

qu_scene_t::channel_entry_t::channel_entry_t(kaitai::kstream* p__io, qu_scene_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::channel_entry_t::_read() {
    m_peq = new peq_t(m__io, this, m__root);
    m_unk1 = m__io->read_bytes(1);
    m_comp = new compressor_t(m__io, this, m__root);
    m_gate = new gate_t(m__io, this, m__root);
    m_unk2 = m__io->read_bytes(1);
    m_geq = new geq_t(m__io, this, m__root);
    m_unk3 = m__io->read_bytes(8);
    m_hpf = new hpf_t(m__io, this, m__root);
    m_unk4 = m__io->read_bytes(1);
    m_delay = new delay_t(m__io, this, m__root);
    m_unk5 = m__io->read_bytes(1);
    m_fader = m__io->read_u2le();
    m_gain = m__io->read_u2le();
    m_trim = m__io->read_u2le();
    m_qu_drive_on_off = m__io->read_u1();
    m_phantom_on_off = m__io->read_u1();
    m_phase_flip_on_off = m__io->read_u1();
    m_unk6 = m__io->read_bytes(1);
    m_mute_on_off = m__io->read_u1();
    m_fx_insert_on_off = m__io->read_u1();
    m_unk7 = m__io->read_bytes(1);
    m_d_snake_on_off = m__io->read_u1();
    m_mutegroup_assignment = m__io->read_u2le();
    m_unk8 = m__io->read_bytes(2);
    m_linked = m__io->read_u1();
    m_unk9 = m__io->read_bytes(3);
    m_preamp_linked = m__io->read_u1();
    m_dynamicssidechain_pan_fader_mute_linked = m__io->read_u1();
    m_unk10 = m__io->read_bytes(2);
    m_dsnake_gain = m__io->read_u2le();
    m_unk11 = m__io->read_bytes(1);
    m_pad_20db_on_off = m__io->read_u1();
    m_name = m__io->read_bytes(6); // removes bytes_to_string
    m_unk12 = m__io->read_bytes(4);
    m_dcagroup_assignment = m__io->read_u2le();
    m_ducker = new ducker_t(m__io, this, m__root);
    m_dsnake_input_number = m__io->read_u1();
    m_unk13 = m__io->read_bytes(8);
}

bool qu_scene_t::channel_entry_t::Write(kaitai::kstream* p_io) {
    m_peq->Write(p_io);
    p_io->write_bytes(m_unk1,1);
    m_comp->Write(p_io);
    m_gate->Write(p_io);
    p_io->write_bytes(m_unk2,1);
    m_geq->Write(p_io);
    p_io->write_bytes(m_unk3,8);
    m_hpf->Write(p_io);
    p_io->write_bytes(m_unk4,1);
    m_delay->Write(p_io);
    p_io->write_bytes(m_unk5,1);
    p_io->write_u2le(m_fader);
    p_io->write_u2le(m_gain);
    p_io->write_u2le(m_trim);
    p_io->write_u1(m_qu_drive_on_off);
    p_io->write_u1(m_phantom_on_off);
    p_io->write_u1(m_phase_flip_on_off);
    p_io->write_bytes(m_unk6,1);
    p_io->write_u1(m_mute_on_off);
    p_io->write_u1(m_fx_insert_on_off);
    p_io->write_bytes(m_unk7,1);
    p_io->write_u1(m_d_snake_on_off);
    p_io->write_u2le(m_mutegroup_assignment);
    p_io->write_bytes(m_unk8,2);
    p_io->write_u1(m_linked);
    p_io->write_bytes(m_unk9,3);
    p_io->write_u1(m_preamp_linked);
    p_io->write_u1(m_dynamicssidechain_pan_fader_mute_linked);
    p_io->write_bytes(m_unk10,2);
    p_io->write_u2le(m_dsnake_gain);
    p_io->write_bytes(m_unk11,1);
    p_io->write_u1(m_pad_20db_on_off);
    p_io->write_bytes(m_name,6); // WARNING COULD BE INCORRECT
    p_io->write_bytes(m_unk12,4);
    p_io->write_u2le(m_dcagroup_assignment);
    m_ducker->Write(p_io);
    p_io->write_u1(m_dsnake_input_number);
    p_io->write_bytes(m_unk13,8);
    return true;
}

qu_scene_t::channel_entry_t::~channel_entry_t() {
    delete m_peq;
    delete m_comp;
    delete m_gate;
    delete m_geq;
    delete m_hpf;
    delete m_delay;
    delete m_ducker;
}

qu_scene_t::channel_entry_t::delay_t::delay_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::channel_entry_t::delay_t::_read() {
    m_time = m__io->read_u2le();
    m_on_off = m__io->read_u1();
}

bool qu_scene_t::channel_entry_t::delay_t::Write(kaitai::kstream* p_io) {
    p_io->write_u2le(m_time);
    p_io->write_u1(m_on_off);
    return true;
}

qu_scene_t::channel_entry_t::delay_t::~delay_t() {
}

qu_scene_t::channel_entry_t::gate_t::gate_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::channel_entry_t::gate_t::_read() {
    m_attack = m__io->read_u2le();
    m_release = m__io->read_u2le();
    m_hold = m__io->read_u2le();
    m_threshold = m__io->read_u2le();
    m_depth = m__io->read_u2le();
    m_in_out = m__io->read_u1();
}

bool qu_scene_t::channel_entry_t::gate_t::Write(kaitai::kstream* p_io) {
    p_io->write_u2le(m_attack);
    p_io->write_u2le(m_release);
    p_io->write_u2le(m_hold);
    p_io->write_u2le(m_threshold);
    p_io->write_u2le(m_depth);
    p_io->write_u1(m_in_out);
    return true;
}

qu_scene_t::channel_entry_t::gate_t::~gate_t() {
}

qu_scene_t::channel_entry_t::compressor_t::compressor_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::channel_entry_t::compressor_t::_read() {
    m_attack = m__io->read_u2le();
    m_release = m__io->read_u2le();
    m_knee = m__io->read_u2le();
    m_ratio = m__io->read_u2le();
    m_threshold = m__io->read_u2le();
    m_gain = m__io->read_u2le();
    m_type = m__io->read_u1();
    m_in_out = m__io->read_u1();
}
bool qu_scene_t::channel_entry_t::compressor_t::Write(kaitai::kstream* p_io) {
    p_io->write_u2le(m_attack);
    p_io->write_u2le(m_release);
    p_io->write_u2le(m_knee);
    p_io->write_u2le(m_ratio);
    p_io->write_u2le(m_threshold);
    p_io->write_u2le(m_gain);
    p_io->write_u1(m_type);
    p_io->write_u1(m_in_out);
    return true;
}

qu_scene_t::channel_entry_t::compressor_t::~compressor_t() {
}

qu_scene_t::channel_entry_t::ducker_t::ducker_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::channel_entry_t::ducker_t::_read() {
    m_attack = m__io->read_u2le();
    m_release = m__io->read_u2le();
    m_hold = m__io->read_u2le();
    m_threshold = m__io->read_u2le();
    m_depth = m__io->read_u2le();
    m_on_off = m__io->read_u1();
    m_trigger_input = m__io->read_u1();
    m_single_gang = m__io->read_u1();
    m_unk3 = m__io->read_bytes(1);
    m_insert = m__io->read_u1();
}

bool qu_scene_t::channel_entry_t::ducker_t::Write(kaitai::kstream* p_io) {
    p_io->write_u2le(m_attack);
    p_io->write_u2le(m_release);
    p_io->write_u2le(m_hold);
    p_io->write_u2le(m_threshold);
    p_io->write_u2le(m_depth);
    p_io->write_u1(m_on_off);
    p_io->write_u1(m_trigger_input);
    p_io->write_u1(m_single_gang);
    p_io->write_bytes(m_unk3,1);
    p_io->write_u1(m_insert);
    return true;
}

qu_scene_t::channel_entry_t::ducker_t::~ducker_t() {
}

qu_scene_t::channel_entry_t::hpf_t::hpf_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::channel_entry_t::hpf_t::_read() {
    m_frequency = m__io->read_u2le();
    m_in_out = m__io->read_u1();
}

bool qu_scene_t::channel_entry_t::hpf_t::Write(kaitai::kstream* p_io) {
    p_io->write_u2le(m_frequency);
    p_io->write_u1(m_in_out);
    return true;
}

qu_scene_t::channel_entry_t::hpf_t::~hpf_t() {
}

qu_scene_t::channel_entry_t::peq_setting_t::peq_setting_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t::peq_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::channel_entry_t::peq_setting_t::_read() {
    m_gain = m__io->read_u2le();
    m_frequency = m__io->read_u2le();
    m_width = m__io->read_u2le();
}
bool qu_scene_t::channel_entry_t::peq_setting_t::Write(kaitai::kstream* p_io) {
    p_io->write_u2le(m_gain);
    p_io->write_u2le(m_frequency);
    p_io->write_u2le(m_width);
    return true;
}

qu_scene_t::channel_entry_t::peq_setting_t::~peq_setting_t() {
}

qu_scene_t::channel_entry_t::peq_t::peq_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::channel_entry_t::peq_t::_read() {
    m_lf = new peq_setting_t(m__io, this, m__root);
    m_lm = new peq_setting_t(m__io, this, m__root);
    m_hm = new peq_setting_t(m__io, this, m__root);
    m_hf = new peq_setting_t(m__io, this, m__root);
    m_lf_shelf = m__io->read_u1();
    m_hf_shelf = m__io->read_u1();
    m_in_out = m__io->read_u1();
}

bool qu_scene_t::channel_entry_t::peq_t::Write(kaitai::kstream* p_io) {
    m_lf->Write(p_io);
    m_lm->Write(p_io);
    m_hm->Write(p_io);
    m_hf->Write(p_io);
    p_io->write_u1(m_lf_shelf);
    p_io->write_u1(m_hf_shelf);
    p_io->write_u1(m_in_out);
    return true;
}

qu_scene_t::channel_entry_t::peq_t::~peq_t() {
    delete m_lf;
    delete m_lm;
    delete m_hm;
    delete m_hf;
}

qu_scene_t::channel_entry_t::geq_t::geq_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::channel_entry_t::geq_t::_read() {
    m_band31 = m__io->read_u2le();
    m_band40 = m__io->read_u2le();
    m_band50 = m__io->read_u2le();
    m_band63 = m__io->read_u2le();
    m_band80 = m__io->read_u2le();
    m_band100 = m__io->read_u2le();
    m_band125 = m__io->read_u2le();
    m_band160 = m__io->read_u2le();
    m_band200 = m__io->read_u2le();
    m_band250 = m__io->read_u2le();
    m_band315 = m__io->read_u2le();
    m_band400 = m__io->read_u2le();
    m_band500 = m__io->read_u2le();
    m_band630 = m__io->read_u2le();
    m_band800 = m__io->read_u2le();
    m_band1k = m__io->read_u2le();
    m_band1k25 = m__io->read_u2le();
    m_band1k6 = m__io->read_u2le();
    m_band2k = m__io->read_u2le();
    m_band2k5 = m__io->read_u2le();
    m_band3k15 = m__io->read_u2le();
    m_band4k = m__io->read_u2le();
    m_band5k = m__io->read_u2le();
    m_band6k3 = m__io->read_u2le();
    m_band8k = m__io->read_u2le();
    m_band10k = m__io->read_u2le();
    m_band12k5 = m__io->read_u2le();
    m_band16k = m__io->read_u2le();
}

bool qu_scene_t::channel_entry_t::geq_t::Write(kaitai::kstream* p_io) {
    p_io->write_u2le(m_band31);
    p_io->write_u2le(m_band40);
    p_io->write_u2le(m_band50);
    p_io->write_u2le(m_band63);
    p_io->write_u2le(m_band80);
    p_io->write_u2le(m_band100);
    p_io->write_u2le(m_band125);
    p_io->write_u2le(m_band160);
    p_io->write_u2le(m_band200);
    p_io->write_u2le(m_band250);
    p_io->write_u2le(m_band315);
    p_io->write_u2le(m_band400);
    p_io->write_u2le(m_band500);
    p_io->write_u2le(m_band630);
    p_io->write_u2le(m_band800);
    p_io->write_u2le(m_band1k);
    p_io->write_u2le(m_band1k25);
    p_io->write_u2le(m_band1k6);
    p_io->write_u2le(m_band2k);
    p_io->write_u2le(m_band2k5);
    p_io->write_u2le(m_band3k15);
    p_io->write_u2le(m_band4k);
    p_io->write_u2le(m_band5k);
    p_io->write_u2le(m_band6k3);
    p_io->write_u2le(m_band8k);
    p_io->write_u2le(m_band10k);
    p_io->write_u2le(m_band12k5);
    p_io->write_u2le(m_band16k);
    return true;
}

qu_scene_t::channel_entry_t::geq_t::~geq_t() {
}

qu_scene_t::routing_entry_t::routing_entry_t(kaitai::kstream* p__io, qu_scene_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::routing_entry_t::_read() {
    int l_mixes = 7;
    m_mixes = new std::vector<route_t*>();
    m_mixes->reserve(l_mixes);
    for (int i = 0; i < l_mixes; i++) {
        m_mixes->push_back(new route_t(m__io, this, m__root));
    }
    m_lr = new route_t(m__io, this, m__root);
    int l_groups = 4;
    m_groups = new std::vector<route_t*>();
    m_groups->reserve(l_groups);
    for (int i = 0; i < l_groups; i++) {
        m_groups->push_back(new route_t(m__io, this, m__root));
    }
    int l_matrices = 2;
    m_matrices = new std::vector<route_t*>();
    m_matrices->reserve(l_matrices);
    for (int i = 0; i < l_matrices; i++) {
        m_matrices->push_back(new route_t(m__io, this, m__root));
    }
    int l_unk = 2;
    m_unk = new std::vector<route_t*>();
    m_unk->reserve(l_unk);
    for (int i = 0; i < l_unk; i++) {
        m_unk->push_back(new route_t(m__io, this, m__root));
    }
    int l_fx_sends = 4;
    m_fx_sends = new std::vector<route_t*>();
    m_fx_sends->reserve(l_fx_sends);
    for (int i = 0; i < l_fx_sends; i++) {
        m_fx_sends->push_back(new route_t(m__io, this, m__root));
    }
}

bool qu_scene_t::routing_entry_t::Write(kaitai::kstream* p_io) {
    int l_mixes = 7;
    for (int i = 0; i < l_mixes; i++) {
        (*m_mixes)[i]->Write(p_io);
    }
    m_lr->Write(p_io);
    int l_groups = 4;
    for (int i = 0; i < l_groups; i++) {
        (*m_groups)[i]->Write(p_io);
    }
    int l_matrices = 2;
    for (int i = 0; i < l_matrices; i++) {
        (*m_matrices)[i]->Write(p_io);
    }
    int l_unk = 2;
    for (int i = 0; i < l_unk; i++) {
        (*m_unk)[i]->Write(p_io);
    }
    int l_fx_sends = 4;
    for (int i = 0; i < l_fx_sends; i++) {
        (*m_fx_sends)[i]->Write(p_io);
    }
    return true;
}

qu_scene_t::routing_entry_t::~routing_entry_t() {
    for (std::vector<route_t*>::iterator it = m_mixes->begin(); it != m_mixes->end(); ++it) {
        delete *it;
    }
    delete m_mixes;
    delete m_lr;
    for (std::vector<route_t*>::iterator it = m_groups->begin(); it != m_groups->end(); ++it) {
        delete *it;
    }
    delete m_groups;
    for (std::vector<route_t*>::iterator it = m_matrices->begin(); it != m_matrices->end(); ++it) {
        delete *it;
    }
    delete m_matrices;
    for (std::vector<route_t*>::iterator it = m_unk->begin(); it != m_unk->end(); ++it) {
        delete *it;
    }
    delete m_unk;
    for (std::vector<route_t*>::iterator it = m_fx_sends->begin(); it != m_fx_sends->end(); ++it) {
        delete *it;
    }
    delete m_fx_sends;
}

qu_scene_t::routing_entry_t::route_t::route_t(kaitai::kstream* p__io, qu_scene_t::routing_entry_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::routing_entry_t::route_t::_read() {
    m_gain = m__io->read_u2le();
    m_pan = m__io->read_u2le();
    m_pre_on_off = m__io->read_u1();
    m_on_off = m__io->read_u1();
    m_unused = m__io->ensure_fixed_contents(std::string("\xFF\xFF", 2));
}

bool qu_scene_t::routing_entry_t::route_t::Write(kaitai::kstream* p_io) {
    p_io->write_u2le(m_gain);
    p_io->write_u2le(m_pan);
    p_io->write_u1(m_pre_on_off);
    p_io->write_u1(m_on_off);
    p_io->write_bytes(m_unused, 2); // MAYBE SHOULD FORCE WRITE OF "\xFF\xFF"???
    return true;
}

qu_scene_t::routing_entry_t::route_t::~route_t() {
}

qu_scene_t::fx_rack_entry_t::fx_rack_entry_t(kaitai::kstream* p__io, qu_scene_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::fx_rack_entry_t::_read() {
    m_unk_type = m__io->read_bytes(2);
    m_name = m__io->read_bytes(20); // REMOVED bytes_to_str
    m_lfcut_rev_hpfin_delay_lfosinerect_chorus_flangetype_flanger_lfoselect_phaser_predelay_gatedverb = m__io->read_u2le();
    m_hfcut_rev_lpfin_delay_monolfosplit_chorus_stereosplit_flanger_monosplit_phaser_type_gatedverb = m__io->read_u2le();
    m_predelay_rev_fbfreq_delay_rate_chorus_speed_flanger_rate_phaser_frequency_symph_attack_gatedverb = m__io->read_u2le();
    m_decaytime_rev_fbslope_delay_thickness_adt_depth_chorus_depth_flanger_depth_symph_hold_gatedverb = m__io->read_u2le();
    m_hfdecay_rev_scatter_delay_wire_adt_monowide_chorus_stereospread_flanger_release_gatedverb = m__io->read_u2le();
    m_hfslope_rev_tapleft_delay_delayseparation_adt_monomultivoice_chorus_regenerate_flanger_monostereowide_gatedverb = m__io->read_u2le();
    m_diffusion_rev_link_delay_doublequadtrack_adt_diffusion_gatedverb = m__io->read_u2le();
    m_size_rev_tapright_delay_speed_adt_mixresonance_phaser_locut_gatedverb = m__io->read_u2le();
    m_shapedecaydelay_rev_feedback_delay_depth_adt_panspeed_chorus_hicut_gatedverb = m__io->read_u2le();
    m_refdetail_rev_width_delay_pandepth_chorus = m__io->read_u2le();
    m_echo1 = m__io->read_u2le();
    m_echo1level_rev_emulationtype_flanger = m__io->read_u2le();
    m_echo2_rev_speedmanual_flanger_resonantstages_phaser = m__io->read_u2le();
    m_echo2level_rev_phasingstages_phaser = m__io->read_u2le();
    m_bodydiffusion_rev_depth_phaser = m__io->read_u2le();
    m_taildiffusion_rev_offset_phaser = m__io->read_u2le();
    m_moddepth = m__io->read_u2le();
    m_modspeed = m__io->read_u2le();
    m_lfdecay = m__io->read_u2le();
    m_lfxover = m__io->read_u2le();
    m_colour = m__io->read_u2le();
    m_colourfreq = m__io->read_u2le();
    m_reflevel = m__io->read_u2le();
    m_decaylevel = m__io->read_u2le();
    m_patchtype = static_cast<qu_scene_t::fx_rack_entry_t::patch_t>(m__io->read_u1());
    m_patchinput = m__io->read_u1();
    m_unk_end = m__io->ensure_fixed_contents(std::string("\x16\x00", 2));
}

bool qu_scene_t::fx_rack_entry_t::Write(kaitai::kstream* p_io) {
    p_io->write_bytes(m_unk_type,2);
    p_io->write_bytes(m_name ,20); // WARNING COULD BE INCORRECT
    p_io->write_u2le(m_lfcut_rev_hpfin_delay_lfosinerect_chorus_flangetype_flanger_lfoselect_phaser_predelay_gatedverb);
    p_io->write_u2le(m_hfcut_rev_lpfin_delay_monolfosplit_chorus_stereosplit_flanger_monosplit_phaser_type_gatedverb);
    p_io->write_u2le(m_predelay_rev_fbfreq_delay_rate_chorus_speed_flanger_rate_phaser_frequency_symph_attack_gatedverb);
    p_io->write_u2le(m_decaytime_rev_fbslope_delay_thickness_adt_depth_chorus_depth_flanger_depth_symph_hold_gatedverb);
    p_io->write_u2le(m_hfdecay_rev_scatter_delay_wire_adt_monowide_chorus_stereospread_flanger_release_gatedverb);
    p_io->write_u2le(m_hfslope_rev_tapleft_delay_delayseparation_adt_monomultivoice_chorus_regenerate_flanger_monostereowide_gatedverb);
    p_io->write_u2le(m_diffusion_rev_link_delay_doublequadtrack_adt_diffusion_gatedverb);
    p_io->write_u2le(m_size_rev_tapright_delay_speed_adt_mixresonance_phaser_locut_gatedverb);
    p_io->write_u2le(m_shapedecaydelay_rev_feedback_delay_depth_adt_panspeed_chorus_hicut_gatedverb);
    p_io->write_u2le(m_refdetail_rev_width_delay_pandepth_chorus);
    p_io->write_u2le(m_echo1);
    p_io->write_u2le(m_echo1level_rev_emulationtype_flanger);
    p_io->write_u2le(m_echo2_rev_speedmanual_flanger_resonantstages_phaser);
    p_io->write_u2le(m_echo2level_rev_phasingstages_phaser);
    p_io->write_u2le(m_bodydiffusion_rev_depth_phaser);
    p_io->write_u2le(m_taildiffusion_rev_offset_phaser);
    p_io->write_u2le(m_moddepth);
    p_io->write_u2le(m_modspeed);
    p_io->write_u2le(m_lfdecay);
    p_io->write_u2le(m_lfxover);
    p_io->write_u2le(m_colour);
    p_io->write_u2le(m_colourfreq);
    p_io->write_u2le(m_reflevel);
    p_io->write_u2le(m_decaylevel);
    p_io->write_u1(m_patchtype);
    p_io->write_u1(m_patchinput);
    p_io->write_bytes(m_unk_end,2); // MAYBE SHOULD FORCE "\x16\x00"???
    return true;
}

qu_scene_t::fx_rack_entry_t::~fx_rack_entry_t() {
}

qu_scene_t::section_end_t::section_end_t(kaitai::kstream* p__io, qu_scene_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::section_end_t::_read() {
    m_number = m__io->read_u1();
    m_terminator = m__io->ensure_fixed_contents(std::string("\xA5\xA5\xA5", 3));
}

bool qu_scene_t::section_end_t::Write(kaitai::kstream* p_io) {
    p_io->write_u1(m_number);
    p_io->write_bytes(m_terminator,3); // MAYBE SHOULD FORCE "\xA5\xA5\xA5"???
    return true;
}

qu_scene_t::section_end_t::~section_end_t() {
}

qu_scene_t::mutegroup_t::mutegroup_t(kaitai::kstream* p__io, qu_scene_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::mutegroup_t::_read() {
    m_name = m__io->read_bytes(6); // removed bytes_to_str
    m_unk = m__io->ensure_fixed_contents(std::string("\x00\x00\x00", 3));
}

bool qu_scene_t::mutegroup_t::Write(kaitai::kstream* p_io) {
    p_io->write_bytes(m_name,6); // WARNING COULD BE INCORRECT
    p_io->write_bytes(m_unk,3); // MAYBE SHOULD FORCE "\x00\x00\x00"???
    return true;
}

qu_scene_t::mutegroup_t::~mutegroup_t() {
}

qu_scene_t::dca_t::dca_t(kaitai::kstream* p__io, qu_scene_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::dca_t::_read() {
    m_level = m__io->read_u2le();
    m_unk = m__io->read_bytes(2);
    m_name = m__io->read_bytes(6); // removed bytes_to_str
    m_unk2 = m__io->ensure_fixed_contents(std::string("\x00\x00\x00\xFF", 4));
}

bool qu_scene_t::dca_t::Write(kaitai::kstream* p_io) {
    p_io->write_u2le(m_level);
    p_io->write_bytes(m_unk,2);
    p_io->write_bytes(m_name,6); // WARNING COULD BE INCORRECT
    p_io->write_bytes(m_unk2,4); // MAYBE SHOULD FORCE "\x00\x00\x00\xFF"???
    return true;
}

qu_scene_t::dca_t::~dca_t() {
}

qu_scene_t::amm_t::amm_t(kaitai::kstream* p__io, qu_scene_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::amm_t::_read() {
    m_lpfilter = m__io->read_u2le();
    m_hpfilter = m__io->read_u2le();
    m_unk = m__io->read_bytes(4);
    int l_priorities = 32;
    m_priorities = new std::vector<uint16_t>();
    m_priorities->reserve(l_priorities);
    for (int i = 0; i < l_priorities; i++) {
        m_priorities->push_back(m__io->read_u2le());
    }
}

bool qu_scene_t::amm_t::Write(kaitai::kstream* p_io) {
    p_io->write_u2le(m_lpfilter);
    p_io->write_u2le(m_hpfilter);
    p_io->write_bytes(m_unk,4);
    int l_priorities = 32;
    for (int i = 0; i < l_priorities; i++) {
        p_io->write_u2le((*m_priorities)[i]);
    }
    return true;
}

qu_scene_t::amm_t::~amm_t() {
    delete m_priorities;
}

qu_scene_t::qu_control_tab_t::qu_control_tab_t(kaitai::kstream* p__io, qu_scene_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::qu_control_tab_t::_read() {
    int l_controls = 15;
    m_controls = new std::vector<qu_control_control_t*>();
    m_controls->reserve(l_controls);
    for (int i = 0; i < l_controls; i++) {
        m_controls->push_back(new qu_control_control_t(m__io, this, m__root));
    }
    m_name = m__io->read_bytes(8); // removed bytes_to_str
    int l_unk = 5;
    m_unk = new std::vector<std::string>();
    m_unk->reserve(l_unk);
    for (int i = 0; i < l_unk; i++) {
        m_unk->push_back(m__io->ensure_fixed_contents(std::string("\x00", 1)));
    }
}

bool qu_scene_t::qu_control_tab_t::Write(kaitai::kstream* p_io) {
    int l_controls = 15;
    for (int i = 0; i < l_controls; i++) {
        (*m_controls)[i]->Write(p_io);
    }
    p_io->write_bytes(m_name,8); // WARNING COULD BE INCCORECT
    int l_unk = 5;
    for (int i = 0; i < l_unk; i++) {
        p_io->write_bytes((*m_unk)[i],1); // MAYBE SHOULD FORCE "\x00"
    }
    return true;
}

qu_scene_t::qu_control_tab_t::~qu_control_tab_t() {
    for (std::vector<qu_control_control_t*>::iterator it = m_controls->begin(); it != m_controls->end(); ++it) {
        delete *it;
    }
    delete m_controls;
    delete m_unk;
}

qu_scene_t::header_t::header_t(kaitai::kstream* p__io, qu_scene_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::header_t::_read() {
    m_magic = m__io->read_bytes(3);
    m_id = m__io->read_u1();
    m_version = new version_t(m__io, this, m__root);
    m_unk1 = m__io->read_bytes(4);
    m_name = m__io->read_bytes(13); // removed bytes_to_str
    m_unk2 = m__io->read_bytes(19);
}

bool qu_scene_t::header_t::Write(kaitai::kstream* p_io) {
    p_io->write_bytes(m_magic,3);
    p_io->write_u1(m_id);
    m_version->Write(p_io);
    p_io->write_bytes(m_unk1,4);
    p_io->write_bytes(m_name,13); // WARNING COULD BE INCORRECT
    p_io->write_bytes(m_unk2,19);
    return true;
}

qu_scene_t::header_t::~header_t() {
    delete m_version;
}

qu_scene_t::header_t::version_t::version_t(kaitai::kstream* p__io, qu_scene_t::header_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::header_t::version_t::_read() {
    m_major = m__io->read_bits_int(7);
    m_const_true = m__io->read_bits_int(1);
    m__io->align_to_byte();
    m_minor = m__io->read_u1();
    m_revision = m__io->read_u2le();
}

bool qu_scene_t::header_t::version_t::Write(kaitai::kstream* p_io) {
    p_io->write_s1(m_major+2);//->write_bits_int(m_major,7);
    //p_io->write_s1(m_const_true); //->write_bits_int(m_const_true,1);
    p_io->write_u1(m_minor);
    p_io->write_u2le(m_revision);
    return true;
}

qu_scene_t::header_t::version_t::~version_t() {
}

qu_scene_t::softkey_t::softkey_t(kaitai::kstream* p__io, qu_scene_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::softkey_t::_read() {
    m_function = m__io->read_u1();
    m_target = m__io->read_u2le();
}

bool qu_scene_t::softkey_t::Write(kaitai::kstream* p_io) {
    p_io->write_u1(m_function);
    p_io->write_u2le(m_target);
    return true;
}

qu_scene_t::softkey_t::~softkey_t() {
}

qu_scene_t::qu_control_control_t::qu_control_control_t(kaitai::kstream* p__io, qu_scene_t::qu_control_tab_t* p__parent, qu_scene_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void qu_scene_t::qu_control_control_t::_read() {
    m_type = m__io->read_u1();
    m_target = m__io->read_u1();
    m_destination = m__io->read_u1();
    m_unk = m__io->ensure_fixed_contents(std::string("\xFF", 1));
}

bool qu_scene_t::qu_control_control_t::Write(kaitai::kstream* p_io) {
    p_io->write_u1(m_type);
    p_io->write_u1(m_target);
    p_io->write_u1(m_destination);
    p_io->write_bytes(m_unk,1); // MAYBE SHOULD FORCE "\xFF"???
    return true;
}

qu_scene_t::qu_control_control_t::~qu_control_control_t() {
}

unsigned int lut[] = {
    0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA, 0x076DC419, 0x706AF48F,
    0xE963A535, 0x9E6495A3, 0x0EDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988,
    0x09B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91, 0x1DB71064, 0x6AB020F2,
    0xF3B97148, 0x84BE41DE, 0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7,
    0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC, 0x14015C4F, 0x63066CD9,
    0xFA0F3D63, 0x8D080DF5, 0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172,
    0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B, 0x35B5A8FA, 0x42B2986C,
    0xDBBBC9D6, 0xACBCF940, 0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,
    0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116, 0x21B4F4B5, 0x56B3C423,
    0xCFBA9599, 0xB8BDA50F, 0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924,
    0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D, 0x76DC4190, 0x01DB7106,
    0x98D220BC, 0xEFD5102A, 0x71B18589, 0x06B6B51F, 0x9FBFE4A5, 0xE8B8D433,
    0x7807C9A2, 0x0F00F934, 0x9609A88E, 0xE10E9818, 0x7F6A0DBB, 0x086D3D2D,
    0x91646C97, 0xE6635C01, 0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E,
    0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457, 0x65B0D9C6, 0x12B7E950,
    0x8BBEB8EA, 0xFCB9887C, 0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,
    0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2, 0x4ADFA541, 0x3DD895D7,
    0xA4D1C46D, 0xD3D6F4FB, 0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0,
    0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9, 0x5005713C, 0x270241AA,
    0xBE0B1010, 0xC90C2086, 0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
    0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4, 0x59B33D17, 0x2EB40D81,
    0xB7BD5C3B, 0xC0BA6CAD, 0xEDB88320, 0x9ABFB3B6, 0x03B6E20C, 0x74B1D29A,
    0xEAD54739, 0x9DD277AF, 0x04DB2615, 0x73DC1683, 0xE3630B12, 0x94643B84,
    0x0D6D6A3E, 0x7A6A5AA8, 0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1,
    0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE, 0xF762575D, 0x806567CB,
    0x196C3671, 0x6E6B06E7, 0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC,
    0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5, 0xD6D6A3E8, 0xA1D1937E,
    0x38D8C2C4, 0x4FDFF252, 0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B,
    0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60, 0xDF60EFC3, 0xA867DF55,
    0x316E8EEF, 0x4669BE79, 0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236,
    0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F, 0xC5BA3BBE, 0xB2BD0B28,
    0x2BB45A92, 0x5CB36A04, 0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,
    0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x026D930A, 0x9C0906A9, 0xEB0E363F,
    0x72076785, 0x05005713, 0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38,
    0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21, 0x86D3D2D4, 0xF1D4E242,
    0x68DDB3F8, 0x1FDA836E, 0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777,
    0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C, 0x8F659EFF, 0xF862AE69,
    0x616BFFD3, 0x166CCF45, 0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2,
    0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB, 0xAED16A4A, 0xD9D65ADC,
    0x40DF0B66, 0x37D83BF0, 0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
    0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6, 0xBAD03605, 0xCDD70693,
    0x54DE5729, 0x23D967BF, 0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94,
    0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D};

uint32_t qu_scene_t::makeCrc(kaitai::kstream* io,bool Input){
    if(Input){ 
        std::istream* file = io->getStream();
        file->clear();
        file->seekg(0,std::ios::beg);
        uint32_t crc = 0x0;
        int j;
        uint8_t array[0x651C];
        file->readsome((char*)array,0x651C);
        for(uint i = 0xC; i<0x651C;i++){
            j = (~((uint8_t)array[i]) ^ (crc)) & 0xFF;
            crc = (lut[j]) ^ 0xFF000000;
        }
        return crc;
    }
    else {
        std::fstream* file = io->getFStream();
        std::istream* file2 = io->getStream();
        std::streampos pos = file->tellp();
        file->clear();
        file2->clear();
        file2->seekg(0,std::ios::beg);
        file->seekp(0,std::ios::beg);
        uint32_t crc = 0x0;
        int j;
        uint8_t array[0x651C];
        file->readsome((char*)array,0x651C);
        for(uint i = 0xC; i<0x651C;i++){
            j = (~((uint8_t)array[i]) ^ (crc)) & 0xFF;
            crc = (lut[j]) ^ 0xFF000000;
        }
        file->seekp(pos);
        return crc;
    }
}