# ft_shmup - TODO

## Collisioni
- [X] Proiettile player colpisce nemico → entrambi (bullet e nemico) `alive = false`, score aumenta
- [X] Nemico raggiunge il player → player perde una vita
- [X] Proiettile nemico colpisce player → player perde una vita

## Player
- [X] Aggiungere attributo `_lives` con getter
- [X] Logica di morte quando `_lives == 0` → `_running = false`

## Nemici che sparano
- [X] Aggiungere timer di sparo in `Enemy`
- [X] Spawn di bullet nemico nel vettore `_enemyBullets` di `Game`
- [X] Update e render di `_enemyBullets`

## HUD
- [X] Score in alto a destra
- [X] Vite rimaste in alto a sinistra
- [X] Tempo di gioco

## Game Over
- [X] Schermata finale con score quando il player muore
- [X] Aspetta un tasto poi esce


- [X] Effetto pellicola/scrolling sfondo

## Opzionale
- [ ] Schermata di start prima del gioco
