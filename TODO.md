# ft_shmup - TODO

## Collisioni
- [ ] Proiettile player colpisce nemico → entrambi (bullet e nemico) `alive = false`, score aumenta
- [ ] Nemico raggiunge il player → player perde una vita
- [ ] Proiettile nemico colpisce player → player perde una vita

## Player
- [ ] Aggiungere attributo `_lives` con getter
- [ ] Logica di morte quando `_lives == 0` → `_running = false`

## Nemici che sparano
- [ ] Aggiungere timer di sparo in `Enemy`
- [ ] Spawn di bullet nemico nel vettore `_enemyBullets` di `Game`
- [ ] Update e render di `_enemyBullets`

## HUD
- [ ] Score in alto a destra
- [ ] Vite rimaste in alto a sinistra
- [ ] Tempo di gioco

## Game Over
- [ ] Schermata finale con score quando il player muore
- [ ] Aspetta un tasto poi esce


- [ ] Effetto pellicola/scrolling sfondo

## Opzionale
- [ ] Schermata di start prima del gioco
